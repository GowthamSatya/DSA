#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool isOp(char c)
    {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')');
    }

    int op_prec(char c)
    {
        switch (c)
        {
        case '-':
            return 1;
        case '+':
            return 1;
        case '*':
            return 2;
        case '/':
            return 3;
        case '^':
            return 4;
        default:
            return -1;
        }
    }

public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s)
    {
        // Your code here
        string ans = "";
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (isOp(s[i]))
            {
                if (s[i] == ')')
                {
                    while (st.top() != '(')
                    {
                        ans += st.top();
                        st.pop();
                    }
                    st.pop();
                }
                else if (s[i] == '(')
                    st.push(s[i]);
                else
                {
                    while (!st.empty() && op_prec(s[i]) <= op_prec(st.top()) && st.top() != '(')
                    {
                        ans += st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
            }
            else
                ans += s[i];
        }

        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--)
    {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}