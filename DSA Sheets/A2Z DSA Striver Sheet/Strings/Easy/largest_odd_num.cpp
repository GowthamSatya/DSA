#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestOddNumber(string num)
    {
        for (int i = num.size() - 1; i >= 0; i--)
        {
            if ((int(num[i]) - 48) & 1)
            {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};

int main()
{
    string s;
    cin >> s;

    Solution sol;
    string ans = sol.largestOddNumber(s);
    cout << ans << endl;
    return 0;
}