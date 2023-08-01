#include <bits/stdc++.h>

using namespace std;
#define MAX_CHARS 256

class Solution
{
public:
    // Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {

        if (str1.size() != str2.size())
            return 0;

        // Your code here
        // hashmap
        map<char, char> mp1, mp2;

        for (int i = 0; i < str1.size(); i++)
        {
            if (mp1[str1[i]] || mp2[str2[i]])
            {
                if (mp1[str1[i]] != str2[i])
                    return 0;
                if (mp2[str2[i]] != str1[i])
                    return 0;
            }
            else
            {
                mp1[str1[i]] = str2[i];
                mp2[str2[i]] = str1[i];
            }
        }

        return 1;
    }
};

int main()
{
    int t;
    cin >> t;
    string s1, s2;
    while (t--)
    {
        cin >> s1;
        cin >> s2;
        Solution obj;
        cout << obj.areIsomorphic(s1, s2) << endl;
    }

    return 0;
}