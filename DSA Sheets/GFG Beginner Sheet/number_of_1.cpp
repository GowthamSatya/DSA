#include <bits/stdc++.h>
using namespace std;

/*
    Problem Statement:
    https://practice.geeksforgeeks.org/problems/set-bits0143/1?page=1&curated[]=8&sortBy=submissions

    Input :
    N = 6

    Output:
    2

    Explanation:
    Binary representation is '110'
    So the count of the set bit is 2.
*/

int setBits(int n)
{
    // Write Your Code here
    int ones = 0;
    while (n > 0)
    {
        ones++;
        n = n & (n - 1);
    }
    return ones;
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
    int N;
    cin >> N;

    int ans = setBits(N);
    cout << ans << endl;
    return 0;
}