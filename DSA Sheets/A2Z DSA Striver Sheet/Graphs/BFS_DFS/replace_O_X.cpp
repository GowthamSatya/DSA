#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    void dfs(int i, int j, vector<vector<char>> &mat, vector<vector<int>> &vis, int n, int m)
    {
        vis[i][j] = 1;

        for (int idx = 0; idx < 4; idx++)
        {
            int nx = i + dx[idx];
            int ny = j + dy[idx];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && mat[nx][ny] == 'O')
                dfs(nx, ny, mat, vis, n, m);
        }
    }

public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++)
        {
            // first row
            if (!vis[0][j] && mat[0][j] == 'O')
            {
                dfs(0, j, mat, vis, n, m);
            }

            // last row
            if (!vis[n - 1][j] && mat[n - 1][j] == 'O')
            {
                dfs(n - 1, j, mat, vis, n, m);
            }
        }

        for (int i = 0; i < n; i++)
        {
            // first col
            if (!vis[i][0] && mat[i][0] == 'O')
                dfs(i, 0, mat, vis, n, m);

            if (!vis[i][m - 1] && mat[i][m - 1] == 'O')
                dfs(i, m - 1, mat, vis, n, m);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && mat[i][j] == 'O')
                {
                    mat[i][j] = 'X';
                }
            }
        }

        return mat;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}