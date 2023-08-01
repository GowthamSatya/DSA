// Problem Statement : https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb1b6/0000000000c4766e

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define all(v) (v).begin(), (v).end()

const int mod = 1e9 + 7;

ll solve()
{
    ll l,n;
    cin >> l >> n;
    vector<ll> v;

    for(ll i=0;i<n;i++){
        char dir;
        ll d;
        cin >> d >> dir;

        dir == 'C' ? v.push_back(d) : v.push_back(-d);
    }

    ll k=0;
    ll count =0;
    for(auto i: v){
        k += i;
        if(abs(k) >= l){
            ll temp = abs(k/l);
            count += temp;

            k < 0 ? k = k+(l*temp) : k = k - (l*temp); 
        }
    }
    return count;
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
        cout << "Case #" << i++ << ": " << solve() << endl;

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;

    return 0;
}