#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool dfs(int i, int clr, vector<int> &color, vector<int> adj[])
    {
        color[i] = clr;

        for (auto nd : adj[i])
        {
            if (color[nd] == -1)
            {
                if (dfs(nd, !clr, color, adj) == false)
                    return false;
            }
            else if (color[nd] == clr)
            {
                return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        // Code here
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (dfs(i, 0, color, adj) == false)
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}