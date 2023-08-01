// Problem Statement : https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb2e1/0000000000c174f2#analysis

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int mod = 1e9 + 7;

int solve()
{
    int n, m, k;
    cin >> m >> n >> k;
    vector<vector<int>> runs(m);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int run = 0;
            cin >> run;
            runs[i].push_back(run);
        }
    }

    int diff = 0;
    for (int i = 0; i < n; i++)
    {
        int max = runs[0][i];
        for (int j = 1; j < m; j++)
        {       
            if(max < runs[j][i]) max = runs[j][i];
        }
        diff += (max - runs[k-1][i]);
    }
    return diff;
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