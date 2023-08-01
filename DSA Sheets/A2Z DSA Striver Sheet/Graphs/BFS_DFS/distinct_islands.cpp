#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void bfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &vis, int a, int b, vector<pair<int, int>> &v)
    {
        queue<pair<int, int>> q;
        q.push({r, c});
        vis[r][c] = 1;

        int n = grid.size();
        int m = grid[0].size();

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            v.push_back({row - a, col - b});
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = row + dx[i];
                int ny = col + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] && !vis[nx][ny])
                {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        set<vector<pair<int, int>>> s;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < m; c++)
            {
                if (grid[r][c] && !vis[r][c])
                {
                    vector<pair<int, int>> v;
                    bfs(r, c, grid, vis, r, c, v);
                    s.insert(v);
                }
            }
        }

        return s.size();
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
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}