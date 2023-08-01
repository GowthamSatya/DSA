#include <bits/stdc++.h>
using namespace std;

/*
    Problem Statement:
    https://practice.geeksforgeeks.org/problems/summed-matrix5834/1?page=1&curated[]=8&sortBy=submissions

    Input :
    n = 4, q = 7

    Output:
    2

    Explaination:
    Matrix becomes
    2 3 4 5
    3 4 5 6
    4 5 6 7
    5 6 7 8
    The count of 7 is 2.
*/

long long sumMatrix(long long n, long long q)
{
    // code here
    if (q > n * 2)
        return 0;

    if (q == n + 1)
        return n;

    if (q > n + 1)
    {
        return 2 * n - q + 1;
    }
    else
        return q - 1;
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
    long long n, q;
    cin >> n >> q;

    long long ans = sumMatrix(n, q);

    cout << ans << endl;
    return 0;
}