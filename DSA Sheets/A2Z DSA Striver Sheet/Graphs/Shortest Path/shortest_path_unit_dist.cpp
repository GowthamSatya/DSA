#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        // code here
        vector<int> adj[N];

        for (auto i : edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        vector<int> dist(N, 1e9);
        queue<int> q;
        dist[src] = 0;
        q.push(src);

        while (!q.empty())
        {
            int nd = q.front();
            q.pop();

            for (auto i : adj[nd])
            {
                if (dist[nd] + 1 < dist[i])
                {
                    dist[i] = 1 + dist[nd];
                    q.push(i);
                }
            }
        }

        vector<int> ans(N, -1);

        for (int i = 0; i < N; i++)
        {
            if (dist[i] != 1e9)
                ans[i] = dist[i];
        }

        return ans;
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
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 2; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}
