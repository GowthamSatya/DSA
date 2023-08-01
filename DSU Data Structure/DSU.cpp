#include <bits/stdc++.h>
using namespace std;

// DSU Data structure which checks if the graph contains the 
// cycle using union and findSet
class DSU{
    int V;
    list<pair<int, int>> l;
    public:
    DSU(int V){
        this->V = V;
    }

    void addEdge(int u, int v){
        l.push_back({u,v});
    }

    int findSet(int i, int parent[]){
        if(parent[i] == -1){
            return i;
        }
        return findSet(parent[i], parent);
    }

    void union_set(int x, int y, int parent[]){
        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);
        if(s1 != s2){
            parent[s1] = s2;
        }
    }

    bool contains_cycle(){
        int *parent = new int[V+1];
        for(int i=0;i<V;i++){
            parent[i] = -1;
        }

        for(auto edge: l){
            int i = edge.first;
            int j = edge.second;

            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);

            if(s1 != s2){
                union_set(s1,s2,parent);
            }else{
                return true;
            }
        }
        delete[] parent;
        return false;
    }
};


int main(){
    DSU d(4);
    d.addEdge(0,1);
    d.addEdge(1,2);
    d.addEdge(2,3);
    d.addEdge(2,0);

    cout<< d.contains_cycle()<<endl;
}