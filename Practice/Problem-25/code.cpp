#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, ans = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int j = 1; j < n; j++)
    {
        if ((arr[j] != arr[j - 1]))
        {
            if (j + 1 < n && arr[j] != arr[j + 1])
                ans++;
            else
                ans += 2;
        }
    }
    cout << ans << endl;
}

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
