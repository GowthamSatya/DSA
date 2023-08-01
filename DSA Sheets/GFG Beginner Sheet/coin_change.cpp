#include <bits/stdc++.h>
using namespace std;

/*
    Problem Statement:
    https://practice.geeksforgeeks.org/problems/coin-change2448/1?page=1&curated[]=8&sortBy=submissions

    Input :
    sum = 4 ,
    N = 3
    coins[] = {1,2,3}

    Output :
    4

    Explaination:
    Four Possible ways are:
    {1,1,1,1},{1,1,2},{2,2},{1,3}.
*/

// Code for recursion + memoisation
// includes extra time for stack space (recursion)
long long int f(int idx, int coins[], int sum, vector<vector<int>> &dp)
{
    // base case
    if (idx == 0)
        return (sum % coins[0] == 0);

    if (dp[idx][sum] != -1)
        return dp[idx][sum];

    long long int pick = (sum - coins[idx] >= 0) ? f(idx, coins, sum - coins[idx], dp) : 0;
    long long int notPick = f(idx - 1, coins, sum, dp);

    return dp[idx][sum] = pick + notPick;
}

long long int count(int coins[], int N, int sum)
{
    // code here.

    // code for memoisation
    // vector<vector<int>> dp(N, vector<int>(sum + 1, -1));
    // return f(N - 1, coins, sum, dp);

    // Code for tabulation
    vector<vector<long long>> dp(N, vector<long long int>(sum + 1, 0));

    // base case
    for (int i = 0; i <= sum; i++)
        dp[0][i] = (i % coins[0] == 0);

    // building up the dp table
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            long long int pick = (j - coins[i] >= 0) ? dp[i][j - coins[i]] : 0;
            long long int notPick = dp[i - 1][j];

            dp[i][j] = pick + notPick;
        }
    }

    return dp[N - 1][sum];
}

int main()
{
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif
    int sum, n;
    cin >> sum >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    long long int ans = count(arr, n, sum);

    cout << ans;
    return 0;
}