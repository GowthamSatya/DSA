#include <bits/stdc++.h>
using namespace std;

int TSP(vector<vector<int>> d, int setOfCities, int pos, int n)
{
    if (setOfCities == (1 << n) - 1)
        return d[pos][0];

    int sol = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if ((setOfCities & (1 << i)) == 0)
        {
            // this place is not visited
            int subProb = d[pos][i] + TSP(d, (1 << i) | setOfCities, i, n);
            sol = min(sol, subProb);
        }
    }
    return sol;
}

int TSP_DP(vector<vector<int>> dist, vector<vector<int>> &dp, int setOfCities, int city, int n)
{
    if (setOfCities == (1 << n) - 1)
        return dist[city][0];

    if (dp[setOfCities][city] != -1)
        return dp[setOfCities][city];

    int sol = INT_MAX;
    for (int i = 0; i < n; i++)
    {

        if ((setOfCities & (1 << i)) == 0)
        {
            // this place is not visited
            int subProb = dist[city][i] + TSP_DP(dist, dp, (1 << i) | setOfCities, i, n);
            sol = min(sol, subProb);
        }
    }
    dp[setOfCities][city] = sol;
    return sol;
}

int main()
{
    vector<vector<int>> dist = {
        {0, 20, 42, 25},
        {20, 0, 30, 34},
        {42, 30, 0, 10},
        {25, 34, 10, 0}};
    int n = 4;
    vector<vector<int>> dp(1 << n, vector<int>(n, -1));
    cout << TSP(dist, 1, 0, 4) << endl;
    cout << TSP_DP(dist, dp, 1, 0, n) << endl;
    return 0;
}