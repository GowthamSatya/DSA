#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int n;
    vector<list<pair<int, int>>> m;

public:
    Graph(int V)
    {
        n = V;
        m.resize(n);
    }

    void addEdge(int u, int v, int w = 1)
    {
        m[u].push_back({v, w});
        m[v].push_back({u, w});
    }

    void printAdjList()
    {
        for (auto i : m)
        {
            for (auto nbr : i)
            {
                cout << nbr.first << '(' << nbr.second << ") ";
            }
            cout << endl;
        }
    }

    int dijkshtras(int s, int dest)
    {
        set<pair<int, int>> q;
        vector<int> dist(n, INT_MAX);
        dist[s] = 0;
        q.insert({dist[s], s});
        while (!q.empty())
        {
            int u = q.begin()->second;
            cout << u << " ";
            q.erase(q.begin());
            for (auto nbr : m[u])
            {
                int v = nbr.first;
                int w = nbr.second;
                if (dist[v] > dist[u] + w)
                {
                    if (q.find({dist[v], v}) != q.end())
                        q.erase(q.find({dist[v], v}));
                    dist[v] = dist[u] + w;
                    q.insert({dist[v], v});
                }
            }
        }
        return dist[dest];
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(0, 3, 7);
    g.addEdge(3, 2, 2);
    g.addEdge(3, 4, 3);
    g.printAdjList();
    cout << g.dijkshtras(0, 4) << endl;
    return 0;
}