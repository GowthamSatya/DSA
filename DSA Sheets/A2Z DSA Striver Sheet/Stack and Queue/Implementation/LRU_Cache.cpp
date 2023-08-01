#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key, data;
    Node *next;
    Node *prev;

    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};

class LRUCache
{
private:
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    int csize;
    unordered_map<int, Node *> pos;

    void addnode(Node *curr)
    {
        Node *temp = head->next;
        curr->next = temp;
        curr->prev = head;
        head->next = curr;
        temp->prev = curr;
    }

    void delnode(Node *curr)
    {
        Node *cprev = curr->prev;
        Node *cnext = curr->next;
        cprev->next = cnext;
        cnext->prev = cprev;
    }

    unordered_map<int, Node *> mp;

public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        csize = cap;
        head->next = tail;
        tail->prev = head;
    }

    // Function to return value corresponding to the key.
    int GET(int key)
    {
        // your code here
        if (mp.find(key) == mp.end())
            return -1;
        Node *temp = mp[key];

        int val = temp->data;
        delnode(temp);
        addnode(temp);

        // reassign the address
        mp[key] = head->next;
        return val;
    }

    // Function for storing key-value pair.
    void SET(int key, int value)
    {
        // your code here
        if (mp.find(key) != mp.end())
        {
            Node *temp = mp[key];
            delnode(temp);
        }
        else if (mp.size() == csize)
        {
            mp.erase(tail->prev->key);
            delnode(tail->prev);
        }

        Node *t = new Node(key, value);
        addnode(t);
        mp[key] = head->next;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
