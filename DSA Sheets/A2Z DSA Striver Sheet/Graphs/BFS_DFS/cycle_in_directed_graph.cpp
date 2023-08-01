#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool dfs(int i, vector<int> adj[], vector<int> &vis, vector<int> &pathVis)
    {
        vis[i] = 1;
        pathVis[i] = 1;

        for (auto nd : adj[i])
        {
            if (!vis[nd])
            {
                if (dfs(nd, adj, vis, pathVis) == true)
                    return true;
            }
            else if (pathVis[nd])
                return true;
        }

        pathVis[i] = 0;
        return false;
    }

public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, adj, vis, pathVis) == true)
                    return true;
            }
        }

        return false;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
