// Problem Statement : https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb1b6/0000000000c47792#analysis

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define all(v) (v).begin(), (v).end()

const int mod = 1e9 + 7;

const int inf = 1e9;
void knapsack(vector<int> distinct_cycle_sizes, vector<vector<int>> dp, vector<int> cnt, int n)
{
    dp[0][0] = 0;
    for (int i = 1; i <= (int)distinct_cycle_sizes.size(); ++i)
    {
        int cs = distinct_cycle_sizes[i - 1];
        dp[i][0] = 0;
        // Using standard sliding window approach.
        for (int j = 0; j < cs; ++j)
        {
            deque<int> dq;
            for (int l = j; l <= n; l += cs)
            {
                dp[i][l] = min(dp[i][l], dp[i - 1][l]);
                int opt = inf, x = -1;
                if (l and !dq.empty())
                {
                    opt = dp[i - 1][dq.front()] + (l - dq.front()) / cs;
                    x = dq.front();
                }
                else if (!l)
                {
                    opt = 0;
                }
                dp[i][l] = min(dp[i][l], opt);
                while (!dq.empty() and dq.front() <= l - cnt[cs] * cs)
                {
                    dq.pop_front();
                }
                while (!dq.empty() and dp[i - 1][l] <= dp[i - 1][dq.back()])
                {
                    dq.pop_back();
                }
                dq.push_back(l);
            }
        }
    }
    vector<int> fans(n + 1);
    int best_right = inf, items_count = distinct_cycle_sizes.size();
    for (int i = n; i >= 1; --i)
    {
        // best_right + 1 accounts for greedy.
        fans[i] = min(dp[items_count][i], best_right + 1);
        best_right = min(best_right, fans[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << fans[i] - 1 << " ";
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << fixed << setprecision(25);
    cerr << fixed << setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();

    int t = 1, i = 1;
    cin >> t;
    while (t--)
    {}
        //cout << "Case #" << i++ << ": " << solve() << endl;

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;

    return 0;
}