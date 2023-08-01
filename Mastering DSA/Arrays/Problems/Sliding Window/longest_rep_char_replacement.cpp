#include <bits/stdc++.h>
using namespace std;

int long_rep_char_len(string s, int k)
{
    if (s == "")
        return 0;

    // Initialize lo and hi pointers
    int lo = 0, hi = 0, res = 0;

    // hashmap to store the occurence of characters
    map<char, int> m;
    int max_f = INT_MIN;
    int count = 0;

    while (hi < s.size())
    {
        // adding the occurence count of a char
        m[s[hi]]++;
        count++;
        // getting the maximum frequency in the map
        max_f = max(max_f, m[s[hi]]);

        if (count - max_f <= k)    // condition for validity
            res = max(res, count); // updating the max window size
        else
        {
            // validation failed
            m[s[lo]]--;
            // update the max_f occurence of characters
            for (auto i : m)
                max_f = max(max_f, i.second);
            lo++;    // shift the lo pointer
            count--; // decrement the count of all in map so that the s[lo] is removed from sliding
        }
        hi++;
    }
    return res;
}

int main()
{
    string s = "ABABBA";
    int k = 2;

    cout << long_rep_char_len(s, k) << endl;
    return 0;
}