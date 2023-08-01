#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[2];

    bool containsKey(int bit)
    {
        return (links[bit] != NULL);
    }

    Node *get(int bit)
    {
        return links[bit];
    }

    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *n = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!n->containsKey(bit))
            {
                n->put(bit, new Node());
            }
            n = n->get(bit);
        }
    }

    int getMax(int num)
    {
        Node *n = root;
        int max_num = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            // node contains opposite key
            if (!n->containsKey(1 - bit))
            {
                max_num = max_num | (1 << i);
                n = n->get(1 - bit);
            }
            else
            {
                n = n->get(bit);
            }
        }
        return max_num;
    }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
    Trie t;
    for (auto i : arr1)
        t.insert(i);

    int maxi = 0;
    for (auto i : arr2)
    {
        maxi = max(maxi, t.getMax(i));
    }

    return maxi;
}

int main()
{
}