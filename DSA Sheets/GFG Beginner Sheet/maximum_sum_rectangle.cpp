#include <bits/stdc++.h>
using namespace std;

/*
    Problem Statement:
    https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1?page=1&curated[]=8&sortBy=submissions

    Input :
    R=4
    C=5
    M=[[1,2,-1,-4,-20],
    [-8,-3,4,2,1],
    [3,8,10,1,3],
    [-4,-1,1,7,-6]]

    Output:
    29
*/

int kadanes(vector<int> &arr, int n)
{
    int sum = 0;
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxi = max(maxi, sum);

        if (sum < 0)
            sum = 0;
    }

    return maxi;
}

int maximumSumRectangle(int R, int C, vector<vector<int>> &M)
{
    // code here
    int ans = INT_MIN;
    for (int i = 0; i < R; i++)
    {
        vector<int> v(C);
        for (int j = i; j < R; j++)
        {
            for (int k = 0; k < C; k++)
            {
                v[k] += M[j][k];
            }
            int maxi = kadanes(v, C);
            ans = max(maxi, ans);
        }
    }

    return ans;
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
    int R, C;
    cin >> R >> C;

    vector<vector<int>> mat(R, vector<int>(C));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            cin >> mat[i][j];
    }

    int ans = maximumSumRectangle(R, C, mat);

    cout << ans << endl;
    return 0;
}