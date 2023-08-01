#include <bits/stdc++.h>
using namespace std;

// Problem : https://leetcode.com/problems/group-anagrams/

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> out;
    int n = strs.size();

    if (n == 0)
        return out;
    if (n == 1)
    {
        out.push_back({strs[0]});
        return out;
    }

    vector<string> dup = strs;

    for (int i = 0; i < n; i++)
        sort(dup[i].begin(), dup[i].end());

    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < out.size(); j++)
        {
            if (out[j][0] == dup[i])
            {
                flag = true;
                out[j].push_back(strs[i]);
            }
        }

        if (!flag)
            out.push_back({dup[i], strs[i]});
    }

    for (int i = 0; i < out.size(); i++)
    {
        reverse(out[i].begin(), out[i].end());
        out[i].pop_back();
    }
    return out;
}
