//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int getAns(vector<int> &bloomDay, int K, int mid)
    {
        int flow = 0, bouqs = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] > mid)
                flow = 0;
            else if (++flow == K)
            {
                bouqs++;
                flow = 0;
            }
        }

        return bouqs;
    }

public:
    int solve(int M, int K, vector<int> &bloomDay)
    {
        if (M * K > bloomDay.size())
            return -1;
        // Code
        int maxi = -1;
        for (auto i : bloomDay)
        {
            maxi = max(maxi, i);
        }

        int lo = 1;
        int hi = maxi;
        int ans = -1;

        while (lo <= hi)
        {
            int mid = (lo + hi) >> 1;

            if (getAns(bloomDay, K, mid) < M)
                lo = mid + 1;
            else
            {
                ans = mid;
                hi = mid - 1;
            }
        }

        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, k;
        cin >> m >> k;
        string s;
        getline(cin, s);
        getline(cin, s);
        int n = s.length();
        int num = 0;
        bool f = 0;
        vector<int> bloomDay;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ')
            {
                if (!f)
                    continue;
                bloomDay.push_back(num);
                num = 0;
                f = 0;
            }
            else
            {
                num = (num * 10) + (s[i] - '0');
                f = 1;
            }
        }
        if (f)
        {
            bloomDay.push_back(num);
        }
        Solution obj;
        cout << obj.solve(m, k, bloomDay) << endl;
    }
    return 0;
}
