#include <bits/stdc++.h>
using namespace std;

/*
    Problem Statement:
    https://practice.geeksforgeeks.org/problems/transpose-of-matrix-1587115621/1?page=1&curated[]=8&sortBy=submissions

    Input :
    N = 4
    mat[][] = {{1, 1, 1, 1},
                {2, 2, 2, 2}
                {3, 3, 3, 3}
                {4, 4, 4, 4}}

    Output:
    {{1, 2, 3, 4},
    {1, 2, 3, 4}
    {1, 2, 3, 4}
    {1, 2, 3, 4}}
*/

void transpose(vector<vector<int>> &matrix, int n)
{
    // code here
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
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
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    transpose(arr, n);

    for (auto i : arr)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}