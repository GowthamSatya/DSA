#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findTwoElement(vector<int> arr, int n)
    {
        // code here

        long long sN = n * (n + 1) / 2;
        long long s2N = sN * ((2 * n) + 1) / 3;

        long long s = 0, s2 = 0;
        for (auto i : arr)
        {
            s += i;
            s2 += ((long long)i * (long long)i);
        }

        long long ans1 = s - sN;
        long long ans2 = s2 - s2N;

        ans2 /= ans1;

        long long x = (ans1 + ans2) / 2;
        long long y = x - ans1;

        return {int(x), int(y)};
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
