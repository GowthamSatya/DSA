#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfsHelper(int node, vector<int> adj[], vector<int> &ans, vector<int> &vis)
    {
        vis[node] = 1;
        ans.push_back(node);

        for (auto i : adj[node])
            if (!vis[i])
                dfsHelper(i, adj, ans, vis);
    }

public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> vis(V, 0);
        vector<int> ans;

        dfsHelper(0, adj, ans, vis);

        return ans;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}