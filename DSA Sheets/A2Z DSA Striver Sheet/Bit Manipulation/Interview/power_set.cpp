#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    vector<string> AllPossibleStrings(string s)
    {
        // Bit Masking Approach
        int n = s.size();
        vector<string> ans;

        int k = 1 << n;

        for (int i = 1; i < k; i++)
        {
            string temp = "";

            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                    temp += s[j];
            }

            ans.push_back(temp);
        }

        sort(ans.begin(), ans.end());
        return ans;
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
