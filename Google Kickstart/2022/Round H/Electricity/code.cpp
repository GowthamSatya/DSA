// Problem Statement : https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb1b6/0000000000c47c8e

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define all(v) (v).begin(), (v).end()

const int mod = 1e9 + 7;

class Graph{
    public:
    int v;
    vector<vector<int>> g;

    Graph(int v){
        this->v =v;
        g.resize(v);
    }

    void addEdge(ll A[], int u,int v){
        if(A[u] == A[v]) return;

        if(A[u] < A[v]) g[v].push_back(u);
        else g[u].push_back(v);
    }

    int BFS(int source){
        queue<int> q;
        vector<bool> vis(v, false);
        q.push(source);
        vis[source] = true;
        vector<int> out;
        while(q.size() > 0){
            auto x = q.front();
            q.pop();
            out.push_back(x);
            for(auto i : g[x]){
                if(vis[i] == false){
                    q.push(i);
                    vis[i] = true;
                }
            }
        }

        return out.size();
    }
};

int solve(){
    int n;
    cin >> n;
    ll arr[n];

    for(int i=0;i<n;i++) cin >> arr[i];

    Graph g(n);
    for(int i=0;i<n-1;i++){
        int x,y;
        cin >> x >> y;
        g.addEdge(arr,x-1,y-1);
    }

    int max = -1;
    for(int i=0;i<n;i++){
        int sol = g.BFS(i);
        if(max < sol) max =sol;
        if(max == n) return max;
    }

    return max;
}   

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << fixed << setprecision(25);
    cerr << fixed << setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();

    int t = 1, i = 1;
    cin >> t;
    while (t--)
        cout << "Case #" << i++ << ": " << solve() << endl;

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    //cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;

    return 0;
}