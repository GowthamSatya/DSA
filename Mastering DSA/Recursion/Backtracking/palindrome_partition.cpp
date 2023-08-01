#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int st, int end)
{
    while (st <= end)
    {
        if (s[st++] != s[end--])
            return false;
    }
    return true;
}

void solve(int idx, vector<string> &path, vector<vector<string>> &ans, string s)
{

    if (idx == s.size())
    {
        ans.push_back(path);
        return;
    }

    for (int i = idx; i < s.size(); i++)
    {
        if (isPalindrome(s, idx, i))
        {
            path.push_back(s.substr(idx, i - idx + 1));
            solve(i + 1, path, ans, s);
            path.pop_back();
        }
    }
}

int main()
{
    string s = "aabb";
    vector<vector<string>> ans;
    vector<string> path;

    solve(0, path, ans, s);

    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}