#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList)
    {
        // storing the elements in a set for a faster access
        unordered_set<string> s(wordList.begin(), wordList.end());
        // Queue to store all the list of strings until we reach the targetWord
        queue<vector<string>> q;
        q.push({beginWord});
        if (s.find(beginWord) != s.end())
            s.erase(beginWord);
        vector<vector<string>> ans;
        while (!q.empty())
        {
            // w is the length of each level
            int w = q.size();
            // dlt keeps track of the elements that are added and to be deleted
            vector<string> dlt;
            // Traversing through every level
            for (int i = 0; i < w; i++)
            {
                auto curr = q.front();
                q.pop();
                string st = curr[curr.size() - 1];
                if (st == endWord)
                {
                    ans.push_back(curr);
                    continue;
                }
                for (int i = 0; i < st.length(); i++)
                {
                    string p = st;
                    for (char j = 'a'; j <= 'z'; j++)
                    {
                        p[i] = j;
                        if (s.find(p) != s.end())
                        {
                            dlt.push_back(p);
                            curr.push_back(p);
                            q.push(curr);
                            // getting back the curr string
                            curr.pop_back();
                        }
                    }
                }
            }
            // removing the used elements
            for (auto it : dlt)
                s.erase(it);
        }
        return ans;
    }
};

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for (string i : a)
        x += i;
    for (string i : b)
        y += i;

    return x < y;
}

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
        vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
        if (ans.size() == 0)
            cout << -1 << endl;
        else
        {
            sort(ans.begin(), ans.end(), comp);
            for (int i = 0; i < ans.size(); i++)
            {
                for (int j = 0; j < ans[i].size(); j++)
                {
                    cout << ans[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}