/*
    Given two strings str1 and str2 and below operations that can be performed on str1.
    Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.

    1. Insert
    2. Remove
    3. Replace
    All of the above operations are of equal cost.
*/

#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int getMinOps(string s1, string s2, int l1, int l2)
{
    if (l1 == 0)
        return l2;
    if (l2 == 0)
        return l1;

    if (s1[l1 - 1] == s2[l2 - 1])
        return getMinOps(s1, s2, l1 - 1, l2 - 1);

    int ins = getMinOps(s1, s2, l1, l2 - 1);
    int del = getMinOps(s1, s2, l1 - 1, l2);
    int rep = getMinOps(s1, s2, l1 - 1, l2 - 1);

    return 1 + min(ins, min(del, rep));
}

int getMinOpsDp(string s1, string s2, int l1, int l2)
{
    int dp[l1 + 1][l2 + 1];

    for (int i = 0; i <= l1; i++)
    {
        for (int j = 0; j <= l2; j++)
        {
            if (i == 0)
            {
                dp[i][j] = j;
            }
            else if (j == 0)
            {
                dp[i][j] = i;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                int ins = dp[i][j - 1];
                int del = dp[i - 1][j];
                int rep = dp[i - 1][j - 1];
                dp[i][j] = 1 + min(ins, min(del, rep));
            }
        }
    }

    for (int i = 0; i <= l1; i++)
    {
        for (int j = 0; j <= l2; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[l1][l2];
}

int main()
{
    string str1, str2;
    str1 = "sunday";
    str2 = "saturday";

    cout << getMinOps(str1, str2, str1.size(), str2.size()) << endl;
    cout << getMinOpsDp(str1, str2, str1.size(), str2.size()) << endl;
}