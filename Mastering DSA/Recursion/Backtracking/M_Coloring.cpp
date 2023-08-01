#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, vector<int> &color, bool graph[101][101], int n, int idx)
{
    for (int k = 0; k < n; k++)
    {
        if (k != node && graph[k][node] == 1 && color[k] == idx)
            return false;
    }
    return true;
}

bool solve(int node, vector<int> &color, int n, int m, bool graph[101][101])
{
    if (node == n)
        return true;

    for (int i = 1; i <= m; i++)
    {
        if (isSafe(node, color, graph, n, i))
        {
            color[node] = i;
            if (solve(node + 1, color, n, m, graph))
                return true;
            color[node] = 0;
        }
    }
    return false;
}

bool graph_coloring(bool graph[101][101], int m, int n)
{
    vector<int> color(n, 0);
    if (solve(0, color, n, m, graph))
        return true;
    return false;
}