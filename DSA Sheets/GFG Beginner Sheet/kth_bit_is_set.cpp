#include <bits/stdc++.h>
using namespace std;

/*
    Problem Statement:
    https://practice.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1?page=1&curated[]=8&sortBy=submissions

    Input :
    N = 4, K = 0

    Output:
    No

    Explanation:
    Binary representation of 4 is 100,
    in which 0th index bit from LSB is not set.
    So, return false.
*/

bool checkKthBit(int n, int k)
{
    // Your code here
    // It can be a one liner logic!! Think of it!!
    return (n & (1 << (k))) ? 1 : 0;
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
    int N, k;
    cin >> N >> k;

    bool ans = checkKthBit(N, k);
    cout << ans << endl;
    return 0;
}