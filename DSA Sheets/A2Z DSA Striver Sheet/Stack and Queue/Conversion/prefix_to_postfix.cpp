#include <bits/stdc++.h>
using namespace std;

class Solution
{

    bool isOp(char c)
    {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }

public:
    string preToPost(string pre)
    {

        reverse(pre.begin(), pre.end());
        stack<string> st;
        string ans = "";

        for (int i = 0; i < pre.size(); i++)
        {
            if (isOp(pre[i]))
            {
                string a = st.top();
                st.pop();
                string b = st.top();
                st.pop();

                ans = (a + b + pre[i]);
                st.push(ans);
            }
            else
            {
                string temp(1, pre[i]);
                st.push(temp);
            }
        }

        return st.top();
    }
};

int main()
{
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--)
    {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}