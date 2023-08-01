#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool canPlace(vector<int> &st, int mid, int k)
    {
        int start = st[0];
        int cnt = 1;

        for (int i = 1; i < st.size(); i++)
        {
            if (st[i] - start >= mid)
            {
                start = st[i];
                cnt++;
            }
            if (cnt == k)
                return true;
        }

        return cnt == k;
    }

public:
    int solve(int n, int k, vector<int> &stalls)
    {

        // Write your code here
        sort(stalls.begin(), stalls.end());
        int lo = 1;
        int hi = stalls[n - 1] - stalls[0];
        int ans = -1;

        while (lo <= hi)
        {
            int mid = (lo + hi) >> 1;

            if (canPlace(stalls, mid, k))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t = 1;
    cin >> t;

    while (t--)
    {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++)
        {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}