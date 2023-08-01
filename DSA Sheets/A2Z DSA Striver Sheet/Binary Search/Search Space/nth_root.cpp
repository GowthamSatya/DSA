#include <bits/stdc++.h>
using namespace std;

class Solution
{
    double multiply(int num, int n)
    {
        double ans = 1.0;

        for (int i = 1; i <= n; i++)
            ans *= num;
        return ans;
    }

public:
    int NthRoot(int n, int m)
    {
        // Code here.
        double lo = 1;
        double hi = m;
        double eps = 1e-6;

        if (m == 1)
            return 1;
        if (n == 1)
            return m;

        while ((hi - lo) > eps)
        {
            double mid = (lo + hi) / 2.0;

            double t = multiply(mid, n);

            if (t == m)
                return mid;

            if (t < m)
                lo = mid;
            else
                hi = mid;
        }

        return -1;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.NthRoot(n, m);
        cout << ans << "\n";
    }
    return 0;
}