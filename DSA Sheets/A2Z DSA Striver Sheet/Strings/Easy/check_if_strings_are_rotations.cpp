#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1, string s2)
    {
        // Your code here
        string t = s1 + s1;
        int n = s2.size();
        int m = s1.size();
        if (n != m)
            return 0;
        for (int i = 0; i < t.size(); i++)
        {
            if (t.substr(i, n) == s2)
                return 1;
        }
        return 0;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution obj;
        cout << obj.areRotations(s1, s2) << endl;
    }
    return 0;
}