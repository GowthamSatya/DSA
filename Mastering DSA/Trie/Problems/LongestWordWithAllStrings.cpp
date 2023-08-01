#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    bool flag = false;
    int cntEndWith = 0;
    int cntPrefix = 0;

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node *newNode)
    {
        links[ch - 'a'] = newNode;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }

    void increaseEnd()
    {
        cntEndWith++;
    }

    void incrementPrefix()
    {
        cntPrefix++;
    }

    void delEnd()
    {
        cntEndWith--;
    }

    void reducePrefix()
    {
        cntPrefix--;
    }

    int getEnd()
    {
        return cntEndWith;
    }

    int getPrefix()
    {
        return cntPrefix;
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

    void insert(string word)
    {
        Node *n = root;

        for (int i = 0; i < word.size(); i++)
        {
            // continuosly check for char and insert new Node if not present
            if (!n->containsKey(word[i]))
                n->put(word[i], new Node());
            // move to reference trie;
            n = n->get(word[i]);
            // increase prefix count
            n->incrementPrefix();
        }
        // then n will point to last node after loop which we will set to true;
        n->setEnd();
        // then increase end count
        n->increaseEnd();
    }

    int countWordsEqualTo(string word)
    {
        Node *n = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (n->containsKey(word[i]))
                n = n->get(word[i]);
            else
                return 0;
        }
        return n->getEnd();
    }

    int countWordsStartWith(string partWord)
    {
        Node *n = root;

        for (int i = 0; i < partWord.size(); i++)
        {
            if (n->containsKey(partWord[i]))
                n = n->get(partWord[i]);
            else
                return 0;
        }

        return n->getPrefix();
    }

    bool search(string word)
    {
        Node *n = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (!n->containsKey(word[i]))
                return false;
            n = n->get(word[i]);
        }

        return n->isEnd();
    }

    bool startsWith(string partWord)
    {
        Node *n = root;

        for (int i = 0; i < partWord.size(); i++)
        {
            if (!n->containsKey(partWord[i]))
                return false;
            n = n->get(partWord[i]);
        }

        return true;
    }

    void erase(string word)
    {
        Node *n = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (n->containsKey(word[i]))
            {
                n = n->get(word[i]);
                n->reducePrefix();
            }
            else
                return;
        }
        n->delEnd();
    }

    bool checkPrefixExists(string word)
    {
        bool fl = true;
        Node *n = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (n->containsKey(word[i]))
            {
                n = n->get(word[i]);
                fl = fl & n->isEnd();
            }
            else
            {
                return false;
            }
        }
        return fl;
    }
};

string completeString(int n, vector<string> &a)
{
    Trie t;
    for (auto i : a)
    {
        t.insert(i);
    }

    string longest = "";
    for (auto i : a)
    {
        if (t.checkPrefixExists(i))
        {
            if (i.size() > longest.size())
                longest = i;
            else if (i.size() == longest.size() && i < longest)
                longest = i;
        }
    }
}

int main()
{
}