#include <bits/stdc++.h>
using namespace std;

vector<int> anagrams(string s, string p)
{
    // initialize lo and hi pointers
    int lo = 0;
    int hi = p.size() - 1;

    map<char, int> s_m, p_m;

    // creating hashmap for p
    for (int i = 0; i < p.size(); i++)
    {
        s_m[s[i]]++;
        p_m[p[i]]++;
    }

    // output vector
    vector<int> ans;

    bool flag = false;
    for (auto i : s_m)
    {
        if (i.second != p_m[i.first])
        {
            flag = true;
            break;
        }
    }

    if (!flag)
        ans.push_back(0);

    while (hi < s.size())
    {
        // sliding window (inc. hi and dec lo.)
        hi++;
        s_m[s[hi]]++;
        s_m[s[lo]]--;
        lo++;

        // equating maps
        flag = false;
        for (auto i : s_m)
        {
            if (i.second != p_m[i.first])
            {
                flag = true;
                break;
            }
        }

        if (!flag)
            ans.push_back(lo);
    }
    return ans;
}

int main()
{
    string s = "cbaebabacd";
    string p = "abc";

    vector<int> out = anagrams(s, p);

    for (auto i : out)
        cout << i << " ";
    cout << endl;
    return 0;
}