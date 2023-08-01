#include <bits/stdc++.h>
using namespace std;

void helper(int idx, string &s, int n)
{
    if (idx == n)
    {
        s[idx] = '\0';
        cout << s << " ";
        return;
    }

    if (s[idx - 1] == '1')
    {
        s[idx] = '0';
        helper(idx + 1, s, n);
    }

    if (s[idx - 1] == '0')
    {
        s[idx] = '0';
        helper(idx + 1, s, n);
        s[idx] = '1';
        helper(idx + 1, s, n);
    }
    return;
}

void generateBinaryStrings(int n)
{
    string s = "";
    s.resize(n);

    s[0] = '0';
    helper(1, s, n);
    s[0] = '1';
    helper(1, s, n);

    return;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        generateBinaryStrings(n);

        cout << endl;
    }
    return 0;
}