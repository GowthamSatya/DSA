/*
The Longest Increasing Subsequence (LIS) problem is to find
the length of the longest subsequence of a given sequence
such that all elements of the subsequence are sorted in
increasing order.

For example, the length of LIS for
{10, 22, 9, 33, 21, 50, 41, 60, 80} is 6
and LIS is {10, 22, 33, 50, 60, 80}.
*/

// DYNAMIC PROGRAMMING APPROACH
// TIME COMPLEXITY : O(n*n)
// SPACE COMPLEXITY : O(n)

#include <bits/stdc++.h>
using namespace std;

int max_el(int arr[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
        if (max < arr[i])
            max = arr[i];

    return max;
}

int LIS(int arr[], int n)
{                    // arr = {3,10,2,11}
    int dp[n] = {1}; // {1,1,1,1}
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + 1);

    return max_el(dp, n);
}

int main()
{
    int arr[] = {3, 10, 2, 11};
    int n = 4;
    cout << LIS(arr, n);
    return 0;
}