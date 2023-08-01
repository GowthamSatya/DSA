// Problem Statement : https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb2e1/0000000000c17491

#include <bits/stdc++.h>
#include <math.h>
using namespace std;

#define ll long long int

const int mod = 1e9 + 7;

int solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1), p_sum(n + 1, 0);
    for (int i = 1; i < n + 1; i++)
    {
        cin >> v[i];
        p_sum[i] = p_sum[i - 1] + v[i];
    }

    int ans = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = i; j < n + 1; j++)
        {
            int current = p_sum[j] - p_sum[i - 1];
            if (current < 0)
                break;
            ans += current;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << fixed << setprecision(25);
    cerr << fixed << setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();

    int t, i = 1;
    cin >> t;
    while (t--)
        cout << "Case #" << i++ << ": " << solve() << endl;

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;

    return 0;
}