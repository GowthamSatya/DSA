#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key, value, cnt;
    Node *next;
    Node *prev;

    Node(int _key, int _value)
    {
        key = _key;
        value = _value;
        cnt = 1; // frequency track in frequency List Map
    }
};

class List
{
public:
    int size;
    Node *head;
    Node *tail;

    List()
    {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0; // INITIALIZING SIZE OF LIST AS 0
    }
    // T.C :- O(1) [ONLY LINK CHANGED]
    void addNode(Node *newNode)
    {
        Node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
        size++;
    }
    // T.C :- O(1) [ONLY LINK CHANGED]
    void delNode(Node *nodeToDelete)
    {
        Node *prevNode = nodeToDelete->prev;
        Node *nextNode = nodeToDelete->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;
    }
};

class LFUCache
{
    // INITIAL CONFIGURATION
    map<int, Node *> keyNode;
    map<int, List *> freqListMap;
    int maxSizeOfCache, minFreq, currSizeOfCache;

public:
    LFUCache(int capacity)
    {
        maxSizeOfCache = capacity;
        minFreq = 0;
        currSizeOfCache = 0;
    }

    void updateFreqListMap(Node *nd)
    {
        keyNode.erase(nd->key);
        freqListMap[nd->cnt]->delNode(nd);

        if (nd->cnt == minFreq && freqListMap[nd->cnt]->size == 0)
        {
            minFreq++;
        }

        List *nextFreqList = new List();

        if (freqListMap.find(nd->cnt + 1) != freqListMap.end())
        {
            nextFreqList = freqListMap[nd->cnt + 1];
        }

        nd->cnt += 1;

        nextFreqList->addNode(nd);

        freqListMap[nd->cnt] = nextFreqList;

        keyNode[nd->key] = nd;
    }

    int get(int key)
    {
        if (keyNode.find(key) != keyNode.end())
        {
            Node *nd = keyNode[key];
            int res = nd->value;

            updateFreqListMap(nd);
            return res;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (maxSizeOfCache == 0)
            return;

        if (keyNode.find(key) != keyNode.end())
        {
            Node *nd = keyNode[key];
            nd->value = value;

            updateFreqListMap(nd);
        }
        else
        {
            if (currSizeOfCache == maxSizeOfCache)
            {
                List *list = freqListMap[minFreq];

                keyNode.erase(list->tail->prev->key);

                freqListMap[minFreq]->delNode(list->tail->prev);
                currSizeOfCache--;
            }
            currSizeOfCache++;
            minFreq = 1;

            List *freqList = new List();

            if (freqListMap.find(minFreq) != freqListMap.end())
            {
                freqList = freqListMap[minFreq];
            }

            Node *toInsert = new Node(key, value);
            freqList->addNode(toInsert);
            keyNode[key] = toInsert;
            freqListMap[minFreq] = freqList;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    int t = 1;
    cin >> t;

    while (t--)
    {
        int capacity;
        cin >> capacity;
        LFUCache *obj = new LFUCache(capacity);

        int runs;
        cin >> runs;
        for (int i = 0; i < runs; i++)
        {
            int s;
            cin >> s;
            if (s == 1)
            {
                int key;
                cin >> key;
                int param_1 = obj->get(key);
                cout << param_1 << endl;
            }
            else
            {
                int key, value;
                cin >> key >> value;
                obj->put(key, value);
            }
        }
    }
}
