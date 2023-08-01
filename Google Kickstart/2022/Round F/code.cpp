// Problem Statement : https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb409/0000000000beefbb

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct Fabric
{
    string color;
    int d, u;
};

bool compare(const Fabric &a, const Fabric &b)
{
    return (a.color.compare(b.color) < 0);
}

bool sort_by_d(const Fabric &a, const Fabric &b)
{
    return (a.d < b.d);
}

bool sort_by_u(const Fabric &a, const Fabric &b)
{
    return (a.u < b.u);
}

int is_equal(const Fabric &f1, const Fabric &f2)
{
    return (f1.color == f2.color && f1.d == f2.d && f1.u == f2.u);
}

void print(vector<Fabric> &v)
{
    for (auto i : v)
        cout << i.color << " " << i.d << " " << i.u << endl;
}

int solve()
{
    int n;
    cin >> n;

    if (n == 1)
        return 1;
    int out = 0;
    vector<Fabric> s, du, tot;
    Fabric colors[n];
    for (int i = 0; i < n; i++)
    {
        string color;
        int u, d;
        cin >> color >> d >> u;
        s.push_back({color, d, u});
        du.push_back({color, d, u});
        tot.push_back({color, d, u});
    }

    sort(s.begin(), s.end(), compare);
    sort(tot.begin(), tot.end(), sort_by_u);
    sort(du.begin(), du.end(), sort_by_d);

    for (int i = 0; i < n; i++)
        if (is_equal(tot[i], s[i]) && is_equal(tot[i], du[i]))
            out++;

    return out;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << fixed << setprecision(25);
    cerr << fixed << setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();

    int t;
    cin >> t;
    int i = 1;
    while (t--)
        cout << "Case #" << i++ << ": " << solve() << endl;

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    return 0;
}