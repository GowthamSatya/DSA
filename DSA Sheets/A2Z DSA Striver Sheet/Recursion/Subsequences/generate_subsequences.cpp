//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(int idx, vector<string> &res, string s, string &temp)
    {
        if (idx == s.size())
        {
            if (temp.size())
                res.push_back(temp);
            return;
        }

        // pick the element;
        temp.push_back(s[idx]);
        solve(idx + 1, res, s, temp);
        temp.pop_back();
        solve(idx + 1, res, s, temp);
    }

public:
    vector<string> AllPossibleStrings(string s)
    {
        // Code here
        vector<string> res;
        string temp;
        solve(0, res, s, temp);

        sort(res.begin(), res.end());

        return res;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string s;
        cin >> s;
        Solution ob;
        vector<string> res = ob.AllPossibleStrings(s);
        for (auto i : res)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
