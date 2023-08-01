#include <bits/stdc++.h>
using namespace std;

// DLL Node Defining
class Node
{
public:
    int key;
    int value;
    int cnt;
    Node *next;
    Node *prev;

    Node(int _key, int _val)
    {
        key = _key;
        value = _val;
        cnt = 1;
    }
};

class DLL
{
public:
    Node *head;
    Node *tail;
    int size;

    DLL()
    {
        size = 0;
        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
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
        size++;
    }

    // deleting a node from DLL
    void delNode(Node *n)
    {
        Node *delPrev = n->prev;
        Node *delNext = n->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        size--;
    }
};

// LRU Object
class LFU
{
    map<int, DLL *> freqMap;
    int cap; // setting the cap of cache
    int currFreq;
    int currSize;
    unordered_map<int, Node *> m; // hash map to store the key and address;

    // constructor
    LFU(int _cap)
    {
        cap = _cap;
        currFreq = 0;
        currSize = 0;
    }

    void updateFreqList(Node *node)
    {
        m.erase(node->key);
        freqMap[node->cnt]->delNode(node);

        if (node->cnt == currFreq && freqMap[node->cnt]->size == 0)
            currFreq++;

        DLL *nextHigherList = new DLL();
        if (freqMap.find(node->cnt + 1) != freqMap.end())
            nextHigherList = freqMap[node->cnt + 1];
        node->cnt += 1;
        nextHigherList->addNode(node);
        freqMap[node->cnt] = nextHigherList;
        m[node->key] = node;
    }

    int get(int key)
    {
        if (m.find(key) == m.end())
        {
            Node *n = m[key];
            int val = n->value;
            updateFreqList(n);
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
    }
};
