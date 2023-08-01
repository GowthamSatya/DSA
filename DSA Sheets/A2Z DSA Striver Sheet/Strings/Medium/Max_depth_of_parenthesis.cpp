#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxDepth(string s)
    {
        if (s == "")
            return 0;

        stack<char> st;
        int maxi = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                st.push(s[i]);
                maxi = max(maxi, (int)st.size());
            }
            else if (s[i] == ')')
            {
                st.pop();
            }
            else
            {
                continue;
            }
        }

        return maxi;
    }
};

int main()
{
    string s;
    cin >> s;

    Solution sol;
    int ans = sol.maxDepth(s);
    cout << ans << endl;
    return 0;
}