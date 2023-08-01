#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Template Node class
template <class T = int>
class Node
{
public:
    T data;
    list<T> neibr; // list to store all connected nodes to a particular node
    Node(T name)
    {
        this->data = name;
    }
};

// Template Graph Class
template <class T = int>
class Graph
{
    unordered_map<T, Node<T> *> m;

public:
    // Constructor
    Graph(vector<T> names) // all nodes array as input parameter
    {
        for (auto i : names)
        {
            m[i] = new Node<T>(i); // converting i/p to node hashmap
        }
    }

    // function to add edge between node i and node j
    void addEdge(T i, T j, bool unDir = true) // undir == biDirectional
    {
        m[i]->neibr.push_back(j);
        if (unDir)
        {
            m[j]->neibr.push_back(i); // example => [1](m) -> [0,2,4](neibr list)
        }
    }

    // function to print adjacency list representation of a graph
    void printAdjList()
    {
        for (auto i : m)
        {
            auto j = i.first;
            Node<T> *n = i.second;
            cout << j << " ==> ";
            for (auto nbr : n->neibr)
            {
                cout << nbr << ' ';
            }
            cout << endl;
        }
    }

    // Breadth Fist Search Function
    void BFS(T source)
    {
        queue<T> q; // Initialize Queue

        /* 
            Initialize visited array with size of number of nodes
            and also the parent array to store the prev nodes and 
            dist array to store the edge weights
        */
        bool *visited = new bool[m.size()]{0};
        bool *parent = new bool[m.size()]{0};
        int *dist = new int[m.size()]{0};

        // Initialize all to -1
        for (int i = 0; i < m.size(); i++)
        {
            parent[i] = -1;
        }

        // push source node to queue
        q.push(source);
        visited[source] = true;
        parent[source] = source;
        dist[source] = 0; // dist from a node to same node = 0
        cout << "BFS ==> ";
        while (!q.empty()) 
        {
            cout << q.front() << " ";

            for (auto i : m) // travesing each node in list
            {
                if (i.first == q.front()) // if node == q.front()
                {
                    Node<T> *n = i.second;
                    for (auto nbr : n->neibr)
                    {
                        if (!visited[nbr]) // if its neighbor's are not visited
                        {
                            q.push(nbr); // push node to queue

                            parent[nbr] = q.front(); // set parent of this nbr to front of queue
                            /* 
                                as edge weights are 1, the distance needed to travel from
                                a source node to its neighbor is 1 unit
                            */
                            dist[nbr] = dist[q.front()] + 1;
                            visited[nbr] = true; // set visited to true
                        }
                    }
                    break;
                }
            }
            q.pop(); // pop the front element of queue
        }
        cout << endl;

        // this loop prints the shortest distance from source node to all other nodes
        for (int i = 0; i < m.size(); i++)
        {
            cout << "Shortest Distance to " << i << " is " << dist[i] << endl;
        }
    }

    // utility function to find DFS 
    void dfsHelper(T node, bool visited[])
    {
        visited[node] = true;
        cout << node << " ";
        for (auto i : m)
        {
            if (i.first == node) // if source is equal to node in list
            {
                Node<T> *n = i.second; // select neibrs list for the source
                for (auto nbr : n->neibr)
                {
                    if (!visited[nbr])
                    {
                        dfsHelper(nbr, visited); // recursive call to its neibr node
                    }
                }
            }
        }

        return;
    }

    // Depth First Search
    void DFS(T source)
    {
        bool *visited = new bool[m.size()]{0};
        cout << endl
             << "DFS Search : ";
        dfsHelper(source, visited);
        cout << endl;
    }
};