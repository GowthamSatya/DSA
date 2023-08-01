#include <iostream>
#include <bits/stdc++.h>
#include "template.h"
using namespace std;

int main()
{
    vector<int> nodes = {0, 1, 2, 3, 4, 5};
    vector<string> cities = {"London", "Bombay", "USA", "Hyderabad", "Germany"};
    Graph<int> g(nodes);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 3);
    g.addEdge(1, 4);
    g.addEdge(4, 2);
    g.addEdge(4, 5);
    g.printAdjList();
    g.BFS(0);
    cout << "=========================================" << endl;

    Graph<string> g2(cities);

    g2.addEdge("London", "USA", false);
    g2.addEdge("London", "Hyderabad", false);
    g2.addEdge("USA", "Hyderbad", false);
    g2.addEdge("Hyderabad", "Bombay");
    g2.addEdge("Bombay", "Germany", false);
    g2.addEdge("USA", "Germany", false);
    g2.printAdjList();

    return 0;
}