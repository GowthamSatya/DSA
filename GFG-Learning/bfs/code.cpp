#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;  
    vector<list<int>> adj;  
public:
    Graph(int V); 
    void addEdge(int v, int w);
    void BFS(int s); 
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
 
void Graph::BFS(int s)
{
    vector<bool> visited(V,false);
    visited[s] = true;
    queue<int> q;
    q.push(s);

    while(!q.empty()){
        int s = q.front();
        cout << s << " ";
        q.pop();

        for(auto i: adj[s]){
            if(!visited[i]){
                visited[i] =true;
                q.push(i);
            }
        }
    }
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(0);
 
    return 0;
}