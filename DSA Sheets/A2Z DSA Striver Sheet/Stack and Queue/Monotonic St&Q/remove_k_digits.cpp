#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeKdigits(string S, int k)
    {
        string ans = "";
        int n = S.size();
        for (int i = 0; i < n; i++)
        {
            while (ans.size() and ans.back() > S[i] and k > 0)
            {
                ans.pop_back();
                k--;
            }
            if (!ans.size() and S[i] == '0')
                ;
            else
                ans += S[i];
        }
        while (ans.size() and k > 0)
        {
            ans.pop_back();
            k--;
        }
        return ans.size() ? ans : "0";
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}