#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubstring(string s)
    {
        // Code here
        int ia = -1, ib = -1, ic = -1;
        int cnt = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'a')
                ia = i;
            else if (s[i] == 'b')
                ib = i;
            else if (s[i] == 'c')
                ic = i;

            if (i > 1)
            {
                cnt += min(ia, min(ib, ic)) + 1;
            }
        }

        return cnt;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution obj;
        cout << obj.countSubstring(s) << endl;
    }
    return 0;
}