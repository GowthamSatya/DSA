#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int characterReplacement(string S, int K)
    {
        // code here
        unordered_map<char, int> mp;
        int n = S.size();
        int ans = -1;
        int i = 0, j = 0;
        int maxCnt = 0;

        while (j < n)
        {
            mp[S[j]]++;
            maxCnt = max(maxCnt, mp[S[j]]);

            while ((j - i + 1) - maxCnt > K)
            {
                mp[S[i]]--;
                i++;
            }

            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
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
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}