#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        stack<char> st;
        string ans = "";

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                if (!st.empty())
                {
                    ans += s[i];
                }
                st.push(s[i]);
            }
            else
            {
                st.pop();
                if (!st.empty())
                {
                    ans += s[i];
                }
            }
        }

        return ans;
    }
};

int main()
{
    string s;
    cin >> s;

    Solution sol;
    string ans = sol.removeOuterParentheses(s);
    cout << ans << endl;
    return 0;
}