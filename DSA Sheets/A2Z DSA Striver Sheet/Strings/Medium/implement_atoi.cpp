#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*You are required to complete this method */
    int atoi(string str)
    {
        // Your code here
        int num = 0;
        // Initially positive
        int sign = 1;
        int i = 0;
        // if starts with negative sign
        // then the number is negative
        if (str[i] == '-')
        {
            sign = -1;
            i++;
        }
        for (; i < str.length(); i++)
        {
            // check for any other symbols apart from numbers 0-9
            if (str[i] == '-')
                return -1;
            else
            {
                if (str[i] - '0' >= 0 && str[i] - '0' < 10)
                    num = num * 10 + str[i] - '0';
                else
                    return -1;
            }
        }
        return sign * num;
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
        Solution ob;
        cout << ob.atoi(s) << endl;
    }
}
// } Driver Code Ends