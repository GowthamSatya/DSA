#include <bits/stdc++.h>
using namespace std;

/*
    Problem Statement:
    https://practice.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1?page=1&curated[]=8&sortBy=submissions

    Input :
    N = 3
    matrix[][] = {{1, 2, 3},
                  {4, 5, 6}
                  {7, 8, 9}}

    Output:
    Rotated Matrix:
    3 6 9
    2 5 8
    1 4 7
*/

void rotateby90(vector<vector<int>> &matrix, int n)
{
    // code here

    // rotate - reverse + transpose

    for (auto &i : matrix)
    {
        reverse(i.begin(), i.end());
    }

    // transpose
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

    rotateby90(arr, n);

    for (auto i : arr)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}