#include <iostream>
#include <map>
using namespace std;
#define ll long long int
#define lld long double

map<ll, ll> dp;

ll calcDp(ll n)
{
    if (dp.find(n) == dp.end())
    {
        ll ans = calcDp(n / 2) + calcDp(n / 3) + calcDp(n / 4);
        dp[n] = max(ans, n);
    }

    return dp[n];
}
void solve(ll n)
{

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    calcDp(n);
    cout << dp[n] << endl;
}

int main() {
	// your code goes here
	ll n;
	while(cin >> n){
	    solve(n);
	}
	return 0;
}
