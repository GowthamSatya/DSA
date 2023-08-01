#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int getCount(int s, vector<int> &piles)
    {
        int ans = 0;

        for (int i = 0; i < piles.size(); i++)
        {
            if (piles[i] <= s)
                ans += 1;
            else
            {
                ans += ceil((double)piles[i] / (double)s);
            }
        }

        return ans;
    }

public:
    int Solve(int N, vector<int> &piles, int H)
    {
        // Code here
        int maxi = -1;
        for (auto i : piles)
            maxi = max(maxi, i);

        int lo = 1;
        int hi = maxi;

        while (lo <= hi)
        {
            int mid = (lo + hi) >> 1;

            if (getCount(mid, piles) <= H)
                hi = mid - 1;
            else
                lo = mid + 1;
        }

        return lo;
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
        vector<int> a;
        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}