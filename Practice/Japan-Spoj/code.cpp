#include <bits/stdc++.h>
using namespace std;

int solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int east[n], west[m];

    for (int i = 0; i < n; i++)
        east[i] = i + 1;
    for (int i = 0; i < m; i++)
        west[i] = i + 1;
}

int main()
{
    int t;
    cin >> t;
    int tN = 0;
    while (t--)
    {
        cout << "Test case " << ++tN << ": " << solve() << endl;
    }
    return 0;
}