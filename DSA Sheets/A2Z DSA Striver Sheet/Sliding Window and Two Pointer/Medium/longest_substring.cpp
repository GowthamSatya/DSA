#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestUniqueSubsttr(string S)
    {
        // code
        vector<int> mp(256, -1);
        int n = S.size();
        int maxi = -1;

        int l = 0, r = 0;

        while (r < n)
        {
            if (mp[S[r]] != -1)
                l = max(l, mp[S[r]] + 1);
            mp[S[r]] = r;
            maxi = max(maxi, r - l + 1);
            r++;
        }

        return maxi;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.longestUniqueSubsttr(str) << endl;
    }
    return 0;
}