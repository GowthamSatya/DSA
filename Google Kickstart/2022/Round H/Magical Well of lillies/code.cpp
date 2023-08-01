// Problem Statement : https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb1b6/0000000000c47e79

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"
#define all(v) (v).begin()(v).end()

ll solve(ll l)
{
    int dp[l + 2];
    for (ll i = 0; i <= l; i++)
        dp[i] = i;

    for (ll i = 2; i <= l; i++)
    {
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        int curr = dp[i];
        curr += 4;
        for (ll j = i + i; j <= l; j += i)
        {
            curr += 2;
            dp[j] = min(dp[j], curr);
        }
    }
    return dp[l];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed << setprecision(25);
    cerr << fixed << setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();

    ll t;
    cin >> t;
    int i=1;
    while (t--)
    {
        ll l;
        cin >> l;
        cout << "Case #" << i++ << ": " << solve(l) << endl;
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;

    return 0;
}