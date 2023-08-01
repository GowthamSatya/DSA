#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s, int i, int j)
    {
        while (i < j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }

    int solve(int ind, int n, string &str, int ans, vector<int> &dp)
    {
        if (ind >= n)
        {
            return 0;
        }
        if (dp[ind] != -1)
            return dp[ind];
        for (int i = ind; i < n; i++)
        {
            int temp = 0;
            int flag = 0;
            if (isPalindrome(str, ind, i))
            {
                temp = 1 + solve(i + 1, n, str, ans, dp);
                flag = 1;
            }
            if (flag == 1)
                ans = min(temp, ans);
        }
        return dp[ind] = ans;
    }

    int palindromicPartition(string str)
    {
        int n = str.size();
        int ans = INT_MAX;
        vector<int> dp(n + 1, -1);
        return solve(0, n, str, ans, dp) - 1;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        Solution ob;
        cout << ob.palindromicPartition(str) << "\n";
    }
    return 0;
}