#include <bits/stdc++.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

struct Point{
    int x,y;
}p0;

Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}

float getDistance(Point *p1, Point *p2){
    float d1 = p2->x-p1->x;
    float   d2 = p2->y-p1->y;
    return (d1*d1 + d2*d2);
}

int orientation(Point p, Point q, Point r){
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
            
    if(val == 0) return 0;
    return val>0 ? 1 :2;
}

int compareO(const void *x, const void *y){
    Point *p1 = (Point *)x;
    Point *p2 = (Point *)y;

    int o= orientation(p0, *p1, *p2);
    if ( o ==0 ){
        return (getDistance(&p0, p2) >= getDistance(&p0,p1)) ? -1 :1;
    }
    return o==2 ? -1:1;
}

void convexHull(Point p[], int n){
    int ymin = p[0].y, min = 0;
   for (int i = 1; i < n; i++)
   {
     int y = p[i].y;
     if ((y < ymin) || (ymin == y &&
         p[i].x < p[min].x))
        ymin = p[i].y, min = i;
   }

   swap(p[0], p[min]);
    p0 = p[0];

    qsort(&p[1],n,sizeof(Point), compareO);

    int m=1;
    for(int i=1;i<n;i++){
        while(i< n-1 and orientation(p0,p[i],p[i+1])==0)
            i++;
        p[m]= p[i];
        m++;
    }

    if(m<3) return;
    stack<Point> S;
    S.push(p[0]);
    S.push(p[1]);
    S.push(p[2]);

    for (int i = 3; i < m; i++)
   {
      while (S.size()>1 && orientation(nextToTop(S), S.top(), p[i]) != 2)
         S.pop();
      S.push(p[i]);
   }
   while (!S.empty())
   {
       Point p = S.top();
       cout << "(" << p.x << ", " << p.y <<")" << endl;
       S.pop();
   }
}

int main(){
    Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
                      {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n = sizeof(points)/sizeof(points[0]);
    convexHull(points, n);
    return 0;
}