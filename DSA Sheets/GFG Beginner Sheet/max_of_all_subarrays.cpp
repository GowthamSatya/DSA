#include <bits/stdc++.h>
using namespace std;

/*
    Problem Statement:
    https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1?page=1&curated[]=8&sortBy=submissions

    Input :
    N = 9, K = 3
    arr[] = 1 2 3 1 4 5 2 3 6

    Output :
    3 3 4 5 5 5 6

    Explaination:
    1st contiguous subarray = {1 2 3} Max = 3
    2nd contiguous subarray = {2 3 1} Max = 3
    3rd contiguous subarray = {3 1 4} Max = 4
    4th contiguous subarray = {1 4 5} Max = 5
    5th contiguous subarray = {4 5 2} Max = 5
    6th contiguous subarray = {5 2 3} Max = 5
    7th contiguous subarray = {2 3 6} Max = 6
*/

vector<int> max_of_subarrays(int *arr, int n, int k)
{
    // your code here
    deque<int> dq;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();

        while (!dq.empty() && arr[dq.back()] < arr[i])
            dq.pop_back();

        dq.push_back(i);
        if (i >= k - 1)
            ans.push_back(arr[dq.front()]);
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
    int n, k;
    cin >> n >> k;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> ans = max_of_subarrays(arr, n, k);

    for (auto i : ans)
        cout << i << " ";
    return 0;
}