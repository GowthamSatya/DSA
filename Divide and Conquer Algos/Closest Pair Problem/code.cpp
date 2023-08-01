#include <bits/stdc++.h>
#include <float.h>
#include <math.h>
using namespace std;

/*
    CLOSEST PAIR OF POINTS USING DIVIDE AND CONQUER ALGORITHM

    TIME COMPLEXITY: O(nlogn)
    T(n) = 2T(n/2) + O(n) + O(n)
    
    SPACE COMPLEXITY: O(logn)
*/

struct Point{
    int x;
    int y;
};

int compareX(const void *x1, const void *x2){
    Point *p1 = (Point *)x1, *p2 = (Point *)x2;
    return (p1->x!=p2->x) ? (p1->x - p2->x ): (p1->y - p2->y);
}

int compareY(const void *x1, const void *x2){
    Point *p1 = (Point *)x1, *p2 = (Point *)x2;
    return (p1->y!=p2->y) ? (p1->y - p2->y): (p1->x - p2->x);
}

float min(float x, float y){
    return x>y ? y : x;
}

float getDistance(Point *p1,Point *p2){
    float d1 = p2->x - p1->x;
    float d2 = p2->y - p1->y;
    return sqrt(d1*d1 + d2*d2);
}

float bruteForce(Point p[], int n){
    float min = FLT_MAX;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(getDistance(&p[i],&p[j]) < min){
                min = getDistance(&p[i], &p[j]);
            }
        }
    }

    return min;
}

float stripClosest(Point strip[],int size, float d){
    float min = d;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size && (strip[j].y-strip[i].y)<min;++j){
            if(getDistance(&strip[i],&strip[j])< min){
                min = getDistance(&strip[i], &strip[j]);
            }
        }
    }

    return min;
}

float closestUtil(Point Px[], Point Py[], int n){
    if(n <= 3){
        return bruteForce(Px, n);
    }

    int mid = n/2;
    Point midPoint = Px[mid];

    Point Pyl[mid];
    Point Pyr[n-mid];
    int li=0,ri=0;
    for(int i=0;i<n;i++){
        if((Py[i].x < midPoint.x || (Py[i].x == midPoint.x && Py[i].y < midPoint.y)) && li<mid)
            Pyl[li++] = Py[i];
        else    
            Pyr[ri++] = Py[i];
    }

    float dl = closestUtil(Px, Pyl,mid);
    float dr = closestUtil(Px+mid, Pyr, n-mid);

    float d = min(dl,dr);

    Point strip[n];
    int j=0;
    for(int i=0;i<n;i++){
        if(abs(Py[i].x - midPoint.x) < d){
            strip[j] = Py[i],j++;
        }
    }

    return stripClosest(strip,j,d);
}

float closest(Point p[], int n){
    Point Px[n];
    Point Py[n];

    for(int i=0;i<n;i++){
        Px[i] = p[i];
        Py[i] = p[i];
    }

    // sort according to x coordinates
    qsort(Px, n, sizeof(Point), compareX);
    // sort according to y coordinates
    qsort(Py, n, sizeof(Point), compareY);

    return closestUtil(Px, Py, n);
}

int main(){
    // Point p1 = {10,11};
    // Point p2 = {5,10};
    // cout << getDistance(&p1, &p2) << endl;

    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    cout << closest(P,n) << endl;

    return 0;
}