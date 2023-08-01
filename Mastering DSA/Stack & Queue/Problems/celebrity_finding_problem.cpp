#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        // code here
        stack<int> s;

        for (int i = 0; i < n; i++)
            s.push(i);

        while (s.size() != 1)
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();

            if (M[a][b])
                s.push(b);
            else
                s.push(a);
        }

        int ans = s.top();
        int z_c = 0;
        int o_c = 0;
        // row checking
        for (int i = 0; i < n; i++)
        {
            if (ans != i && M[ans][i] == 0)
                z_c++;
            if (ans != i && M[i][ans] == 1)
                o_c++;
        }

        if (o_c == z_c)
            return ans;
        return -1;
    }
};