#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(int i, int j, vector<vector<int>> &m, int n, vector<string> &ans, string s, vector<vector<int>> &vis, int dX[], int dY[])
    {
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(s);
            return;
        }

        string dir = "DLRU";
        for (int r = 0; r < 4; r++)
        {
            int ni = i + dX[r];
            int nj = j + dY[r];

            if (ni >= 0 && nj >= 0 && ni < n && nj < n && m[ni][nj] == 1 && !vis[ni][nj])
            {
                vis[i][j] = 1;
                solve(ni, nj, m, n, ans, s + dir[r], vis, dX, dY);
                vis[i][j] = 0;
            }
        }
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        int dX[] = {1, 0, 0, -1};
        int dY[] = {0, -1, 1, 0};

        if (m[0][0] == 1)
            solve(0, 0, m, n, ans, "", vis, dX, dY);
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
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}