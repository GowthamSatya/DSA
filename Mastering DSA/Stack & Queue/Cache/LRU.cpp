#include <bits/stdc++.h>
using namespace std;

// DLL Node Defining
class Node
{
public:
    int key;
    int value;
    Node *next;
    Node *prev;

    Node(int _key, int _val)
    {
        key = _key;
        value = _val;
    }
};

// LRU Object
class LRU
{
    // defining head and tail
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    int cap;                      // setting the cap of cache
    unordered_map<int, Node *> m; // hash map to store the key and address;

    // constructor
    LRU(int _cap)
    {
        cap = _cap;
        head->next = tail;
        tail->next = head;
    }

    // addNode() to add node to DLL
    void addNode(Node *n)
    {
        // adding node to head->next
        Node *temp = head->next;
        n->next = temp;
        n->prev = head;
        head->next = n;
        temp->prev = n;
    }

    // deleting a node from DLL
    void delNode(Node *n)
    {
        Node *delPrev = n->prev;
        Node *delNext = n->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int _key)
    {
        // if key is present in hashmap
        if (m.find(_key) != m.end())
        {
            // getting the address of node in DLL
            Node *resNode = m[_key];
            // getting the value of resNode
            int res = resNode->value;
            // updating the address of hashmap to least recently used
            m.erase(_key);
            delNode(resNode);
            addNode(resNode);
            m[_key] = head->next;
            return res;
        }
        return -1;
    }

    // adding an element to cache
    int put(int _key, int _value)
    {
        // if element is present in cache update its least recently used in hashmap and DLL
        if (m.find(_key) != m.end())
        {
            Node *existing = m[_key];
            m.erase(_key);
            delNode(existing);
        }

        // if Cache is full delete the least recently used element which is at tail of the DLL
        if (m.size() == cap)
        {
            m.erase(tail->prev->key);
            delNode(tail->prev);
        }

        // add the newNode to head->next;
        addNode(new Node(_key, _value));
        m[_key] = head->next;
    }
};