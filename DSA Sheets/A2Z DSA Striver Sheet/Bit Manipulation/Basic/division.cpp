#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long divide(long long dividend, long long divisor)
    {
        // code here
        long long a = dividend, b = divisor;
        int sign = 0;
        if (a == 0)
            return 0;
        if (b == 0)
            return INT_MAX;

        if ((a < 0 && b > 0) || (a > 0 && b < 0))
            sign = 1;

        if (a < 0)
            a = -a;
        if (b < 0)
            b = -b;

        long long int ans = 0, temp = 0;

        for (int i = 31; i >= 0; i--)
        {
            if (temp + (b << i) <= a)
            {
                temp += b << i;
                ans += 1 << i;
            }
        }

        if (sign)
            return -ans;
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {

        long long a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.divide(a, b) << "\n";
    }

    return 0;
}