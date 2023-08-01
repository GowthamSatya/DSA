//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool Search(int n, vector<int> &v, int k)
    {
        // Code here
        int l = 0;
        int r = n - 1;

        while (l <= r)
        {
            int m = l + (r - l) / 2;

            if (v[m] == k)
                return true;
            if (v[l] == v[m] && v[m] == v[r])
                l++, r--;
            else if (v[l] <= v[m])
            {
                if (v[l] <= k && k <= v[m])
                {
                    r = m - 1;
                }
                else
                    l = m + 1;
            }
            else
            {
                if (v[m] <= k && k <= v[r])
                {
                    l = m + 1;
                }
                else
                    r = m - 1;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
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
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends