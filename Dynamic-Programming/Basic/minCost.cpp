#include <bits/stdc++.h>
using namespace std;

const int r = 3;
const int c = 3;
/*
Given a cost matrix cost[][] and a position (m, n) in cost[][],
write a function that returns cost of minimum cost path to reach
(m, n) from (0, 0). Each cell of the matrix represents a cost
to traverse through that cell. The total cost of a path to reach
(m, n) is the sum of all the costs on that path (including both
source and destination). You can only traverse down, right and
diagonally lower cells from a given cell, i.e., from a given
cell (i, j), cells (i+1, j), (i, j+1), and (i+1, j+1) can be traversed.
You may assume that all costs are positive integers.

Ex:
            [1,2,3]
cost_arr =  [4,8,2]        --> minCost = 1+2+2+3 = 8
            [1,5,3]
*/

// DP Approach

int minCost(int cost[r][c], int m, int n)
{
    int dp[r][c] = {0};
    dp[0][0] = cost[0][0];

    for (int i = 1; i <= n; i++)
        dp[i][0] = dp[i - 1][0] + cost[i][0];
    for (int j = 1; j <= m; j++)
        dp[0][j] = dp[0][j - 1] + cost[0][j];

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            dp[i][j] = min(dp[i - 1][j - 1],
                           min(dp[i][j - 1], dp[i - 1][j])) +
                       cost[i][j];
    }

    return dp[m][n];
}

int main()
{
    int arr[3][3] = {
        {1, 2, 3},
        {4, 8, 2},
        {1, 5, 3}};

    cout << "Minimum Cost : " << minCost(arr, 2, 2) << endl;
    return 0;
}
