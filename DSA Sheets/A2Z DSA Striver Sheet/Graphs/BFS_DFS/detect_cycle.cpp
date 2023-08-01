#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool detect(int src, vector<int> adj[], vector<int> &vis)
    {
        vis[src] = 1;
        queue<pair<int, int>> q;

        q.push({src, -1});

        while (!q.empty())
        {
            int node = q.front().first;
            int cameFrom = q.front().second;

            q.pop();

            for (auto i : adj[node])
            {
                if (!vis[i])
                {
                    vis[i] = 1;
                    q.push({i, node});
                }
                else if (cameFrom != i)
                {
                    return true;
                }
            }
        }

        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                int flag = detect(i, adj, vis);
                if (flag)
                    return true;
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
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}