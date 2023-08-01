#include <bits/stdc++.h>
using namespace std;

/*
    Problem Statement:
    https://practice.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1?page=1&curated[]=8&sortBy=submissions

    Input :
    N = 3

    Output:
    move disk 1 from rod 1 to rod 3
    move disk 2 from rod 1 to rod 2
    move disk 1 from rod 3 to rod 2
    move disk 3 from rod 1 to rod 3
    move disk 1 from rod 2 to rod 1
    move disk 2 from rod 2 to rod 3
    move disk 1 from rod 1 to rod 3
    7

    Explanation:
    For N=3 , steps will be
    as follows in the example and total
    7 steps will be taken.
*/

void dotoh(int N, int a, int b, int c, long long &ans)
{
    if (N > 0)
    {
        dotoh(N - 1, a, c, b, ans);
        cout << "move disk " << N << " from rod " << a << " to rod " << c << endl;
        ans++;
        dotoh(N - 1, b, a, c, ans);
    }
}

long long toh(int N, int from, int to, int aux)
{
    // Your code here
    long long ans = 0;
    dotoh(N, from, aux, to, ans);
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
    int N;
    cin >> N;

    long long ans = toh(N, 1, 3, 2);
    cout << ans << endl;
    return 0;
}