#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#define lt long int
using namespace std;

int main()
{
    lt t;
    cin >> t;
    while (t--)
    {
        lt n, ans = 0;
        cin >> n;
        lt arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        lt maxx = arr[n - 1];
        for (auto x : arr)
        {
            ans = max(ans, maxx - x);
        }

        cout << ans << endl;
    }
}