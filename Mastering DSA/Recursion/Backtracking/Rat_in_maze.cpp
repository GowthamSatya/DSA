#include <bits/stdc++.h>
using namespace std;

// Time Complexity => O(4^(n*m))
// Space Complexity => O(n*m)
void solve(int i, int j, vector<vector<int>> &arr, vector<vector<int>> &visited, vector<string> &ans, string str, int n)
{
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(str);
        return;
    }

    // Down
    if (i + 1 < n && !visited[i + 1][j] && arr[i + 1][j] == 1)
    {
        visited[i][j] = 1;
        solve(i + 1, j, arr, visited, ans, str + "D", n);
        visited[i][j] = 0;
    }

    // Left
    if (j - 1 >= 0 && !visited[i][j - 1] && arr[i][j - 1] == 1)
    {
        visited[i][j] = 1;
        solve(i, j - 1, arr, visited, ans, str + 'L', n);
        visited[i][j] = 0;
    }

    // Right
    if (j + 1 < n && !visited[i][j + 1] && arr[i][j + 1] == 1)
    {
        visited[i][j] = 1;
        solve(i, j + 1, arr, visited, ans, str + 'R', n);
        visited[i][j] = 0;
    }

    // Up
    if (i - 1 >= 0 && !visited[i - 1][j] && arr[i - 1][j] == 1)
    {
        visited[i][j] = 1;
        solve(i - 1, j, arr, visited, ans, str + 'U', n);
        visited[i][j] = 0;
    }
}

int main()
{
    int n = 4;
    vector<vector<int>> arr = {{1, 0, 0, 0},
                               {1, 1, 0, 1},
                               {1, 1, 0, 0},
                               {0, 1, 1, 1}};
    vector<vector<int>> visited(n, vector<int>(n, 0));
    vector<string> ans;
    string path = "";
    solve(0, 0, arr, visited, ans, path, n);

    for (auto i : ans)
        cout << i << endl;

    return 0;
}