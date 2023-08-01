// Problem Statement : https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb2e1/0000000000c17c82

#include <bits/stdc++.h>
#include <math.h>
using namespace std;

#define ll long long int

const int mod = 1e9 + 7;

double getDistance(pair<int, int> p)
{
    return (p.first * p.first + p.second * p.second);
}

pair<int, int> solve()
{
    ll rs, rh;
    cin >> rs >> rh;

    vector<pair<int, int>> red;
    vector<pair<int, int>> yellow;
    vector<ll> red_d, yellow_d;

    int r, y;
    cin >> r;
    if (r != 0)
    {
        red.resize(r);
        for (int i = 0; i < r; i++)
            cin >> red[i].first >> red[i].second;
    }

    cin >> y;
    if (y != 0)
    {
        yellow.resize(y);
        for (int i = 0; i < y; i++)
            cin >> yellow[i].first >> yellow[i].second;
    }

    int sr = 0, sy = 0;
    ll min_r = LONG_LONG_MAX, min_y = LONG_LONG_MAX;
    if (r != 0)
    {
        for (auto i : red)
        {
            ll d = getDistance(i);
            if (d <= (rs + rh)*(rs + rh))
            {
                red_d.push_back(d);
                if (d < min_r)
                    min_r = d;
            }
        }
    }

    if (y != 0)
    {
        for (auto i : yellow)
        {
            ll d = getDistance(i);
            if (d <= (rs + rh)*(rs + rh))
            {
                yellow_d.push_back(d);
                if (d < min_y)
                    min_y = d;
            }
        }
    }

    if(min_r < min_y){
        for(auto i : red_d)
            if(i <= min_y) sr++;
    }
    if(min_r > min_y)
        for(auto i : yellow_d)
            if(i <= min_r) sy++;

    // if (field.size() > 0)
    // {
    //     sort(field.begin(), field.end());
    //     int i = 0, j = 0;
    //     if (field[0].second == 'r')
    //         while (field[i++].second == 'r')
    //             sr++;

    //     if (field[0].second == 'y')
    //         while (field[j++].second == 'y')
    //             sy++;
    // }

    return {sr, sy};
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
    {
        pair<int, int> out = solve();
        cout << "Case #" << i++ << ": " << out.first << " " << out.second << endl;
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;

    return 0;
}