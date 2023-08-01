#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int Knapsack(int v[], int w[], int k, int n)
{
    // RECURSIVE APPROACH (TIME COMPLEXITY: O(2^n))

    // if (i == 5)
    //     return 0;
    // else if (k < 0)
    //     return -1;
    // else
    //     return max(Knapsack(v, w, k, i + 1), Knapsack(v, w, k - w[i], i + 1) + v[i]);

    // DYNAMIC PROGRAMMING APPROACH (TIME COMPLEXITY: O(n*k)) (SPACE COMPLEXITY: O(n*k)) TOP-DOWN

    int i, j;
    vector<vector<int>> K(n + 1, vector<int>(k + 1));

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= k; j++)
        {
            if (i == 0 || j == 0)
                K[i][j] = 0;
            else if (w[i - 1] < j)
                K[i][j] = max(v[i - 1] + K[i - 1][j - w[i - 1]], K[i - 1][j]);
            else
                K[i][j] = K[i - 1][j];
        }
    }

    return K[n][k];
}

int main()
{
    int values[5] = {20, 30, 15, 25, 10};
    int weights[5] = {6, 13, 5, 10, 3};
    int capacity = 20;

    cout << Knapsack(values, weights, capacity, 5) << endl;
}