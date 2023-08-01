#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*You are required to complete this method */
    int helper(string str, int idx)
    {
        if (idx == 0)
            return str[0] - '0';

        int temp = helper(str, idx - 1);
        return temp * 10 + (str[idx] - '0');
    }

    int atoi(string str)
    {
        // Your code here

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] - 'a' >= 0)
                return -1;
            else if (str[i] - '0' < 0 && i > 0)
                return -1;
        }

        if (str[0] == '-')
        {
            return -1 * helper(str.substr(1, str.size() - 1), str.size() - 2);
        }

        return helper(str, str.size() - 1);
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
        Solution ob;
        cout << ob.atoi(s) << endl;
    }
}