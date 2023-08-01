#include <bits/stdc++.h>
using namespace std;

bool isAdjacent(unordered_map<int, vector<int>> &graph, int i, int j)
{
    for (auto k : graph[i])
    {
        if (k == j)
            return true;
    }
    return false;
}

void printpath(vector<int> &path)
{
    int size = path.size();
    for (int i = 0; i < size; i++)
        cout << path[i] << " ";
    cout << endl;
}

int isNotVisited(int x, vector<int> &path)
{
    int size = path.size();
    for (int i = 0; i < size; i++)
        if (path[i] == x)
            return 0;
    return 1;
}

vector<int> findpaths(unordered_map<int, vector<int>> &g, int src, int dst,
                      int v)
{
    queue<vector<int>> q;

    vector<int> path;
    path.push_back(src);
    q.push(path);
    while (!q.empty())
    {
        path = q.front();
        q.pop();
        int last = path[path.size() - 1];

        if (last == dst)
            return path;

        for (int i = 0; i < g[last].size(); i++)
        {
            if (isNotVisited(g[last][i], path))
            {
                vector<int> newpath(path);
                newpath.push_back(g[last][i]);
                q.push(newpath);
            }
        }
    }
    return path;
}

int getCost(vector<int> &p, vector<int> &d)
{
    int sum = 0;
    for (auto i : p)
    {
        cout << i << " ";
        sum += d[i];
    }
    cout << endl;
    return sum;
}

int findTax(int A, vector<vector<int>> &B, vector<vector<int>> &C, vector<int> &D)
{
    const int MOD = 10e9 + 7;
    int ans = 0;

    unordered_map<int, vector<int>> graph(A);

    for (auto i : B)
    {
        graph[i[0] - 1].push_back(i[1] - 1);
        graph[i[1] - 1].push_back(i[0] - 1);
    }

    for (auto i : C)
    {
        if (!isAdjacent(graph, i[0] - 1, i[1] - 1))
        {
            D[i[0] - 1] /= 2;
            D[i[1] - 1] /= 2;
        }
    }

    for (auto i : D)
        cout << i << endl;

    for (auto i : C)
    {
        vector<int> p = findpaths(graph, i[0] - 1, i[1] - 1, A);
        ans += getCost(p, D);
        cout << ans << endl;
    }

    return ans % MOD;
}

int main()
{
    int A = 3;
    vector<vector<int>> B = {{1, 2}, {2, 3}};

    vector<vector<int>> C = {{1, 3}, {1, 2}};
    vector<int> D = {2, 4, 2};

    cout << findTax(A, B, C, D) << endl;
}