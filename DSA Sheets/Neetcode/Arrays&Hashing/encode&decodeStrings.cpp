#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.lintcode.com/problem/659/

string encode(vector<string> &strs)
{
    string encoded = "";
    for (auto i : strs)
    {
        int n = i.size();
        encoded += n + "#" + i;
    }
    cout << encoded << endl;
    return encoded;
}

vector<string> decode(string &str)
{
    vector<string> decoded;

    for (int i = 0; i < str.size(); i++)
    {
        int j = i;

        while (str[j] != '#')
            j++;
    }
    return decoded;
}

int main()
{
    vector<string> strs = {"lint", "code"};

    string e = encode(strs);
    vector<string> out = decode(e);

    cout << e << endl;
    for (auto i : out)
        cout << i << endl;
    return 0;
}