#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to reverse words in a given string.
    string reverseWords(string S)
    {
        reverse(S.begin(), S.end());

        int st = 0;
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == '.')
            {
                reverse(S.begin() + st, S.begin() + i);
                st = i + 1;
            }
        }
        reverse(S.begin() + st, S.end());

        return S;
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
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}