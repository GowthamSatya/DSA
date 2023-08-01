#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    vector<pair<int, int>> *l;
    int V;

public:
    Graph(int v)
    {
        V = v;
        l = new vector<pair<int, int>>[v];
    }

    void addEdge(int x, int y, int w)
    {
        l[x].push_back({y, w});
        l[y].push_back({x, w});
    }

    int prim_mst()
    {
        // creating array to check if vertex is visited
        bool *visited = new bool[V]{0};
        int ans = 0;
        // Creating a min-heap using priroity queue
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
        int m = 0;
        // pushing {weight, node} as it need to sort according to least weight
        Q.push({0, 0});
        while (!Q.empty())
        {
            // Pick edge with minimum weight
            auto best = Q.top();
            Q.pop();
            int to = best.second;
            int weight = best.first;

            if (visited[to])
            {
                // move to other edge;
                continue;
            }
            ans += weight;
            visited[to] = true;
            cout << ans << " " << weight << endl;
            m = max(m, weight);
            // add the new edges in the queue
            for (auto x : l[to])
            {
                if (!visited[x.first])
                {
                    Q.push({x.second, x.first});
                }
            }
        }
        return m;
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1, 5);
    g.addEdge(1, 2, 13);
    g.addEdge(0, 2, 3);
    g.addEdge(0, 3, 11);
    g.addEdge(0, 4, 6);

    cout << g.prim_mst() << endl;
    cout << "==========" << endl;
    Graph g2(4);
    g2.addEdge(0, 1, 10);
    g2.addEdge(1, 2, 2);
    g2.addEdge(0, 2, 24);
    g2.addEdge(1, 3, 15);
    g2.addEdge(2, 3, 7);

    cout << g2.prim_mst() << endl;
    return 0;
}