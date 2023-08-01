#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree
{
public:
    Node *root;
    BinaryTree(int d)
    {
        root = new Node(d);
        root->left = NULL;
        root->right = NULL;
    }

    ~BinaryTree()
    {
        delete root;
    }

    int getHeight()
    {
        int lHeight = 0, rHeight = 0;
        Node *ltemp = root;
        Node *rtemp = root;

        while (ltemp != NULL)
        {
            lHeight++;
            ltemp = ltemp->left;
        }

        while (rtemp != NULL)
        {
            rHeight++;
            rtemp = rtemp->right;
        }

        return lHeight > rHeight ? lHeight : rHeight;
    }

    // Time Complexity : O(n) : Space Complexity
    int getDiameter(Node *root, int *height)
    {
        int lH, rH = 0;

        if (root == NULL)
        {
            *height = 0;
            return 0;
        }

        int lDiam = getDiameter(root->left, &lH);
        int rDiam = getDiameter(root->right, &rH);

        *height = max(lH, rH) + 1;

        return max(lH + rH + 1, max(lDiam, rDiam));
    }

    Node *insertNode(int d)
    {
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            if (curr->left == NULL)
            {
                curr->left = new Node(d);
                return root;
            }
            else
            {
                q.push(curr->left);
            }

            if (curr->right == NULL)
            {
                curr->right = new Node(d);
                return root;
            }
            else
            {
                q.push(curr->right);
            }
        }
        return root;
    }

    Node *deleteNode(int k)
    {
        if (root->left == NULL && root->right == NULL)
        {
            if (root->data == k)
                return NULL;
            else
                return root;
        }

        queue<Node *> q;
        q.push(root);

        Node *keyNode = NULL;
        Node *curr, *last;
        while (!q.empty())
        {
            curr = q.front();
            q.pop();

            if (curr->data == k)
            {
                keyNode = curr;
            }

            if (curr->left)
            {
                last = curr;
                q.push(curr->left);
            }
            if (curr->right)
            {
                last = curr;
                q.push(curr->right);
            }
        }

        if (keyNode)
        {
            keyNode->data = curr->data;
            if (last->right == curr)
                last->right = NULL;
            else
                last->left = NULL;
        }
        return root;
    }

    void inOrderIterative()
    {
        stack<Node *> s;
        Node *curr = root;
    
        while (s.empty() == false || curr != NULL)
        {

            while (curr != NULL)
            {
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top();
            s.pop();
            cout << curr->data << " ";

            curr = curr->right;
        }

        cout << endl;
    }

    void levelOrderTraversal()
    {
        int h = getHeight();
        for (int i = 1; i <= h; i++)
        {
            printLevelOrder(root, i);
        }
    }

    void printLevelOrder(Node *root, int level)
    {
        if (root == NULL)
            return;

        if (level == 1)
            cout << root->data << " ";
        if (level > 1)
        {
            printLevelOrder(root->left, level - 1);
            printLevelOrder(root->right, level - 1);
        }
    }

    void inorder(Node *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(Node *root)
    {
        if (root == NULL)
            return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node *root)
    {
        if (root == NULL)
            return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
};

int main()
{
    BinaryTree *b1 = new BinaryTree(10);
    b1->insertNode(4);
    b1->insertNode(5);
    cout << b1->getHeight() << endl;
    b1->inorder(b1->root);
    cout << endl;
    b1->preorder(b1->root);
    cout << endl;
    b1->postorder(b1->root);
    cout << endl;
    b1->levelOrderTraversal();
    cout << endl;
    b1->inOrderIterative();
}
