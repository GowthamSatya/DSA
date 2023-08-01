#include <iostream>
#include <bits/stdc++.h>
#include "template.h"
using namespace std;

int main()
{
    vector<int> nodes = {0, 1, 2, 3, 4, 5, 6};
    Graph<int> g(nodes);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 5);
    g.addEdge(0, 4);
    g.addEdge(4, 3);
    g.printAdjList();
    g.DFS(1);

    return 0;
}
