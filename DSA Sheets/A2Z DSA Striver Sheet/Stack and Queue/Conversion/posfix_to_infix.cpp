#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool isOp(char c)
    {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }

public:
    string postToInfix(string exp)
    {
        // Write your code here
        stack<string> st;
        string ans = "";

        for (int i = 0; i < exp.size(); i++)
        {
            if (isOp(exp[i]))
            {
                string a = st.top();
                st.pop();
                string b = st.top();
                st.pop();

                ans = ('(' + b + exp[i] + a + ')');
                st.push(ans);
            }
            else
            {
                string temp(1, exp[i]);
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
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    }
    fclose(stdout);

    return 0;
}