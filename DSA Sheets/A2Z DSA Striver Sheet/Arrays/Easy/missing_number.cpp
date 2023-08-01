#include <bits/stdc++.h>
using namespace std;
#define ll long long

int missingNumber(int a[], int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int i = 0, n;
        cin >> n;
        int a[n + 5];
        for (i = 0; i < n - 1; i++)
            cin >> a[i];

        cout << missingNumber(a, n) << endl;
    }
}

int missingNumber(int A[], int N)
{

    // Brute Force (TLE)
    // map<int, int> m;

    // for (int i = 0; i < N - 1; i++)
    // {
    //     m[A[i]]++;
    // }

    // for (int i = 1; i <= N; i++)
    // {
    //     if (m[i] == 0)
    //         return i;
    // }

    // return -1;

    // Optimized-1
    // int sum = N * (N + 1) / 2;

    // int arr_sum = 0;

    // for (int i = 0; i < N - 1; i++)
    //     arr_sum += A[i];

    // return sum - arr_sum;

    // Optimised-2;
    int x1 = 0, x2 = 0;
    for (int i = 0; i < N - 1; i++)
    {
        x1 ^= A[i];
    }

    for (int i = 1; i <= N; i++)
        x2 ^= i;

    return x1 ^ x2;
}