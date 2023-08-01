#include <bits/stdc++.h>
using namespace std;

int knapSackRec(int wts[], int cost[], int n, int w){
    if(n == 1 and w >= wts[0]) return cost[0];
    if(n == 1 and w < wts[0]) return 0;

    int d1 = cost[n-1] + knapSackRec(wts, cost,n-1, w-wts[n-1]);
    int d2 = 0 + knapSackRec(wts, cost,n-1, w);

    return max(d1, d2);
}

int knapSackDp(int wts[], int cost[], int n, int w){
    int dp[w + 1];
    memset(dp, 0, sizeof(dp));
 
    for (int i = 1; i < n + 1; i++) {
        for (int j = w; j >= 0; j--) {
            if (wts[i - 1] <= j)
                dp[j] = max(dp[j],
                            dp[j - wts[i - 1]] + cost[i - 1]);
        }
    }
    return dp[w];
}

int main(){
    int cost[3] = {10,15,40};
    int wts[3] = {1,2,3};
    int W =6;
    cout << knapSackRec(wts, cost,3,W)<< endl;
    cout << knapSackDp(wts, cost,3,W)<< endl;
}