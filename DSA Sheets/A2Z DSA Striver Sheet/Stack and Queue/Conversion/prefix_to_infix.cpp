#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool isOp(char c)
    {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }

public:
    string preToInfix(string pre_exp)
    {
        // Write your code here
        string ans = "";
        stack<string> st;
        for (int i = pre_exp.size() - 1; i >= 0; i--)
        {
            if (isOp(pre_exp[i]))
            {
                string a = st.top();
                st.pop();
                string b = st.top();
                st.pop();

                ans = ("(" + a + pre_exp[i] + b + ")");

                st.push(ans);
            }
            else
            {
                string temp(1, pre_exp[i]);
                st.push(temp);
            }
        }

        return ans;
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
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends