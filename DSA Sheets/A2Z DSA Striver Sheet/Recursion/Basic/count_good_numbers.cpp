#include <bits/stdc++.h>
using namespace std;

class Solution
{
    long long mod = 1e9 + 7;
    long long power(long long x, long long n)
    {
        if (n == 0)
            return 1;

        long long ans = power(x, n / 2);
        ans *= ans;

        ans %= mod;

        if (n % 2)
            ans *= x;
        ans %= mod;
        return ans;
    }

public:
    int countGoodNumbers(long long n)
    {
        long long odd = n / 2;
        long long even = n / 2 + n % 2;

        return (power(5, even) * power(4, odd)) % mod;
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;

        Solution sol;
        int ans = sol.countGoodNumbers(n);
        cout << ans << endl;
    }

    return 0;
}