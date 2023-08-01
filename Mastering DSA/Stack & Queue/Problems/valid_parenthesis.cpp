#include <bits/stdc++.h>
using namespace std;

bool is_valid(string par)
{
    // initialize the stack and size of string
    stack<int> st;
    int n = par.size();

    for (int i = 0; i < n; i++)
    {
        // if opening bracket push it to stack
        if (par[i] == '(' || par[i] == '{' || par[i] == '[')
            st.push(par[i]);

        //  if closing bracket pop it from stack and check if not empty or top item = ")"
        if (par[i] == ')' || par[i] == '}' || par[i] == ']')
        {
            if (st.empty())
                return false;
            st.pop();
        }
    }

    return st.empty();
}

int main()
{
    string par = "[{}({[(()())]})]";
    cout << is_valid(par) << endl;
    return 0;
}