#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(vector<vector<int>> &ans, vector<vector<int>> &image, vector<int> dx, vector<int> dy,
             int sr, int sc, int newColor, int init)
    {
        ans[sr][sc] = newColor;

        int n = image.size();
        int m = image[0].size();

        for (int i = 0; i < 4; i++)
        {
            int nx = sr + dx[i];
            int ny = sc + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && image[nx][ny] == init && ans[nx][ny] != newColor)
                dfs(ans, image, dx, dy, nx, ny, newColor, init);
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        // Code here

        int n = image.size();
        int m = image[0].size();
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        vector<vector<int>> ans(n, vector<int>(m, 0));

        ans = image;

        dfs(ans, image, dx, dy, sr, sc, newColor, image[sr][sc]);

        return ans;
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
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans)
        {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}