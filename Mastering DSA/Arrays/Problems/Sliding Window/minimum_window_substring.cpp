#include <bits/stdc++.h>
using namespace std;

string get_min_window(string s, string t)
{
    int ans = INT_MAX;
    int lo = 0, hi = 0, head = 0; // start of window

    vector<int> map(128, 0);
    int cnt = t.size();

    for (auto i : t)
        map[i]++;

    while (hi < s.size())
    {
        if (map[s[hi++]]-- > 0)
            cnt--;

        while (cnt == 0)
        {
            if (hi - lo < ans)
                ans = hi - (head = lo);
            if (map[s[lo++]]++ == 0)
                cnt++;
        }
    }
    return ans == INT_MAX ? "" : s.substr(head, ans);
}

int main()
{
    string s = "adobecodebanc";
    string t = "abc";
    cout << get_min_window(s, t) << endl;
    return 0;
}