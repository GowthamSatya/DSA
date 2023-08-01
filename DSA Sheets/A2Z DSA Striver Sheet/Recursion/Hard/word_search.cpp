#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool helper(vector<vector<char>> &board, string word, int i, int j, int n, int m, int t)
    {
        if (t >= word.size())
            return true;
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] == '.' || word[t] != board[i][j])
            return false;

        if (word.size() == 1 && word[t] == board[i][j])
            return true;

        board[i][j] = '.';
        bool temp = false;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {-1, 1, 0, 0};

        for (int a = 0; a < 4; a++)
        {
            for (int b = 0; b < 4; b++)
            {
                temp = temp || helper(board, word, i + dx[a], j + dy[b], n, m, t + 1);
            }
        }

        board[i][j] = word[t];

        return temp;
    }

public:
    bool isWordExist(vector<vector<char>> &board, string word)
    {
        // Code here
        int n = board.size();
        if (n == 0)
            return false;
        int m = board[0].size();
        if (m == 0)
            return false;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (word[0] == board[i][j])
                {
                    if (helper(board, word, i, j, n, m, 0))
                        return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> board(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> board[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(board, word);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends