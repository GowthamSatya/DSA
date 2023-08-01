#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(string arr[], int N)
    {
        // your code here
        sort(arr, arr + N);
        string n = arr[0], m = arr[N - 1], ans = "";
        for (int i = 0; i < n.size(); i++)
        {
            if (n[i] == m[i])
            {
                ans += n[i];
            }
            else
                break;
        }

        if (ans.size() == 0)
            return "-1";
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        Solution ob;
        cout << ob.longestCommonPrefix(arr, n) << endl;
    }
}