#include <bits/stdc++.h>
using namespace std;

/*
int arr[] = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of jumps to";
    cout << " reach the end is " << minJumps(arr, n);
*/

// Dynamic Programming Approach

int minJumps(vector<int> arr, int n)
{
    int *jumps = new int[n]; // intialize dp array of size n

    // base case
    if (n == 0 || arr[0] == 0)
        return INT_MAX;

    jumps[0] = 0; // self explanatory

    for (int i = 1; i < n; i++)
    {
        jumps[i] = INT_MAX; // intial case
        for (int j = 0; j < i; j++)
        {
            // storing the best possible step at each index
            if (i <= j + arr[j] && jumps[j] != INT_MAX)
            {
                jumps[i] = min(jumps[i], jumps[j] + 1);
                break;
            }
        }
    }
    return jumps[n - 1];
}

// Greedy Approach Best
int minJumpsGreedy(vector<int> arr, int n)
{
    int ans = 0;
    int currFar = 0, currEnd = 0;

    for (int i = 0; i < n - 1; i++)
    {
        currFar = max(currFar, i + arr[i]);

        if (i == currEnd)
        {
            ans++;
            currEnd = currFar;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    cout << "Minimum number of jumps to";
    cout << " reach the end is " << minJumpsGreedy(arr, arr.size());
    return 0;
}