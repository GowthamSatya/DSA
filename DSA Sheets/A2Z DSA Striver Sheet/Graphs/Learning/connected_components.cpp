#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        // code here
        int cnt = 0;
        queue<int> q;
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++)
        {

            if (!vis[i])
            {

                cnt++;
                q.push(i);
                vis[i] = 1;
            }

            while (!q.empty())
            {
                int t = q.front();
                q.pop();

                for (int j = 0; j < V; j++)
                {
                    if (t != j && adj[t][j] == 1 && !vis[j])
                    {
                        vis[j] = 1;
                        q.push(j);
                    }
                }
            }
        }

        return cnt;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, x;
        cin >> V;

        vector<vector<int>> adj;

        for (int i = 0; i < V; i++)
        {
            vector<int> temp;
            for (int j = 0; j < V; j++)
            {
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution ob;
        cout << ob.numProvinces(adj, V) << endl;
    }
    return 0;
}