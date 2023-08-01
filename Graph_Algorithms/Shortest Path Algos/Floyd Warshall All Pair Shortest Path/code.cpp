#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floyd_warshall(vector<vector<int>> graph)
{
    vector<vector<int>> dist(graph);
    int V = graph.size();
    // Phases, in Kth phase we include vertices (1,2,...k) as intermediate vertices
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    return dist;
}

int main()
{
    vector<vector<int>> graph = {
        {0, 10, 24, 999},
        {10, 0, 2, 15},
        {24, 2, 0, 7},
        {999, 15, 7, 0}};

    auto res = floyd_warshall(graph);
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph.size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}