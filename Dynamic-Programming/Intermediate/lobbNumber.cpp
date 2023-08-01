#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int binomial(int n,int k){
    int dp[n+1][k+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=min(i,k);j++){
            if(j == 0|| j== i) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    return dp[n][k];
}

int lobbsNum(int n,int m){
    return ((2*m+1)*binomial(2*n, m+n)/(m+n+1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed << setprecision(25);
    cerr << fixed << setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();

    cout << lobbsNum(5,3) << endl;

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;

    return 0;
}