#include <bits/stdc++.h>
using namespace std;

int LCS(char w1[], char w2[], int m, int n){
    int dp[m+1][n+1];

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i ==0 || j == 0) dp[i][j] = 0;
            else if(w1[i-1] == w2[j-1]) 
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}

int main()
{
    char w1[] = "kayla";
    char w2[] = "jayla";

    int m = strlen(w1);
    int n = strlen(w2);
    cout << m << " " << n << endl;
    cout << LCS(w1, w2, m, n);
}