#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n);
// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    void solve(int op, int cl, vector<string> &res, string &s)
    {
        if (op == 0 && cl == 0)
        {
            res.push_back(s);
            return;
        }

        if (op != 0)
        {
            string op1 = s;
            op1.push_back('(');
            solve(op - 1, cl, res, op1);
        }

        if (cl > op)
        {
            string op2 = s;
            op2.push_back(')');
            solve(op, cl - 1, res, op2);
        }
    }

public:
    vector<string> AllParenthesis(int n)
    {
        // Your code goes here
        int op = n, cl = n;
        vector<string> res;

        string str;

        solve(op, cl, res, str);

        return res;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        vector<string> result = ob.AllParenthesis(n);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << "\n";
    }
    return 0;
}