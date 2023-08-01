// Works for negative edges unlike dijkshtra's
/*
=== Approach ===

1) Initialize dist = INTMAX dist[src] = 0;
2) Relax all edges v-1 times
*/
#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int V;
    vector<vector<int>> m;

    Graph(int v)
    {
        V = v;
    }

    void addEdge(int u, int v, int w)
    {
        m.push_back({u, v, w});
    }

    vector<int> bellmans(int source)
    {
        vector<int> dist(V+1, INT_MAX);
        dist[source] = 0;

        for (int j = 0; j < V - 1; j++)
        {
            for (auto i : m)
            {
                int u = i[0];
                int v = i[1];
                int w = i[2];
                cout << u << " " << v << " " << w << endl;
                if (dist[u] != INT_MAX and dist[v] > dist[u] + w)
                    dist[v] = dist[u] + w;
            }
        }

        for(auto i : m){
            int u = i[0];
                int v = i[1];
                int w = i[2];
            if(dist[u] != INT_MAX and dist[v]>dist[u]+w){
                cout << "Negative wt cycle found" << endl;
                exit(0);
            }
        }

        return dist;
    }
};

int main()
{
    Graph g(3);
    
    g.addEdge(1,2,3);
    g.addEdge(1,3,-10);
    g.addEdge(2,3,4);

    vector<int> d = g.bellmans(1);

    for(auto i : d){
        cout << i << endl;
    }

    return 0;
}