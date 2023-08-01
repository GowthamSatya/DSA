#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
    {
        // Code here
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());

        st.erase(startWord);

        while (!q.empty())
        {
            string s = q.front().first;
            int t = q.front().second;
            q.pop();

            if (s == targetWord)
                return t;

            for (int i = 0; i < s.size(); i++)
            {
                char original = s[i];

                for (char c = 'a'; c <= 'z'; c++)
                {
                    s[i] = c;
                    if (st.find(s) != st.end())
                    {
                        st.erase(s);
                        q.push({s, t + 1});
                    }
                }
                s[i] = original;
            }
        }

        return 0;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<string> wordList(n);
        for (int i = 0; i < n; i++)
            cin >> wordList[i];
        string startWord, targetWord;
        cin >> startWord >> targetWord;
        Solution obj;
        int ans = obj.wordLadderLength(startWord, targetWord, wordList);
        cout << ans << "\n";
    }
    return 0;
}