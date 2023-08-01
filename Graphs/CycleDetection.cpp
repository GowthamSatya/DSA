#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    list<int> *l;
    int V;

public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[v];
    }

    void addEdge(int m, int n)
    {
        l[m].push_back(n);
        l[n].push_back(m);
    }

    bool dfs(int node, vector<bool> &visited, int parent)
    {
        visited[node] = true;
        for (auto i : l[node])
        {
            if (!visited[i])
            {
                bool nbr_found_cycle = dfs(i, visited, node);
                if (nbr_found_cycle)
                    return true;
            }
            else if (i != parent)
                return true;
        }
        return false;
    }

    bool cycle_present()
    {
        vector<bool> visited(V, false);
        return dfs(0, visited, -1);
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << g.cycle_present() << endl;
    return 0;
}