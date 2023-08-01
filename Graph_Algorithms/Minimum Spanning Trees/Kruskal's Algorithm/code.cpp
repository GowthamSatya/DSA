// Kruskals Algorithm For minimum spanning tree
// Greedy Algorithm
// Time Complexity : O(ElogV)
 
#include <bits/stdc++.h>
using namespace std;

class DSU {
    int* parent;
    int* rank;
 
public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];
 
        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
 
    // Find function with path compression optimization
    int find(int i)
    {
        if (parent[i] == -1)
            return i;
 
        return parent[i] = find(parent[i]);
    }
   
    // Union function with union by rank optimization
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);
 
        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Graph{
    int V;
    vector<vector<int>> m;

    public:
    Graph(int v){
        V= v;
    }

    void addEdge(int x,int y,int w){
        m.push_back({w,x,y});
    }

    void kruskals_mst(){
        // sorting all edges in increasing order of weights
        sort(m.begin(),m.end());

        // Initialize a DSU data structure with all nodes belong to different set
        DSU d(V);
        int ans = 0;

        // traverse all edges in the graph
        for(auto e : m){
            int w = e[0];
            int x = e[1];
            int y = e[2];
            
            // if x and y donot belong to the same set we unite them
            if (d.find(x) != d.find(y)) {
                d.unite(x, y);
                ans += w;
                cout << x << " -- " << y << " == " << w
                     << endl;
            }
        }
         cout << "Minimum Cost Spanning Tree: " << ans; 
    }
};

int main(){
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);
 
      // Function call
    g.kruskals_mst();
    return 0;
    return 0;
}