#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int v)
    {
        val = v;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree
{
    Node *head = NULL, *prev = NULL; // for DLL conversion
    int ans = 0;                     // to get height and diameter

    void printLeftViewUtil(Node *root, map<int, int> &m, int l)
    {
        if (root == NULL)
            return;

        if (m[l] == NULL)
            m[l] = root->val;

        printLeftViewUtil(root->left, m, l + 1);
        printLeftViewUtil(root->right, m, l + 1);
    }

    void printRightViewUtil(Node *root, map<int, int> &m, int l)
    {
        if (root == NULL)
            return;

        if (m[l] == NULL)
            m[l] = root->val;

        printRightViewUtil(root->right, m, l + 1);
        printRightViewUtil(root->left, m, l + 1);
    }

public:
    Node *buildTree()
    {
        Node *root = NULL;

        int data;
        cout << "Enter Value : ";
        cin >> data;

        if (data == -1)
            return NULL;

        root = new Node(data);

        cout << "Enter Left of " << data << " : ";
        root->left = buildTree();

        cout << "Enter Right of " << data << " : ";
        root->right = buildTree();

        return root;
    }

    void inorder(Node *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }

    void preorder(Node *root)
    {
        if (root == NULL)
            return;

        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node *root)
    {
        if (root == NULL)
            return;

        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }

    int getHeight(Node *root)
    {
        if (root == NULL)
            return NULL;

        int lH = getHeight(root->left);
        int rH = getHeight(root->right);

        return max(lH, rH) + 1;
    }

    int getSize(Node *root)
    {
        if (root == NULL)
            return 0;

        return getSize(root->left) + getSize(root->right) + 1;
    }

    int getMaxNode(Node *root)
    {
        if (root == NULL)
            return INT_MIN;

        return max(max(getMaxNode(root->left), getMaxNode(root->right)), root->val);
    }

    void levelOrder(Node *root)
    {
        queue<Node *> q;
        if (root == NULL)
            return;

        q.push(root);
        q.push(NULL); // to print each level in new line

        while (!q.empty())
        {
            Node *t = q.front();
            q.pop();
            if (t == NULL)
            {
                if (q.empty())
                    return;

                q.push(NULL);
                cout << "\n";
            }
            cout << t->val << " ";

            if (t->left != NULL)
                q.push(t->left);
            if (t->right != NULL)
                q.push(t->right);
        }
    }

    void printLeftView(Node *root)
    {
        map<int, int> m;
        printLeftViewUtil(root, m, 0); // root, map, level\

        for (auto i : m)
            cout << i.second << " ";
        cout << endl;
    }

    void printRightView(Node *root)
    {
        map<int, int> m;
        printRightViewUtil(root, m, 0); // root, map, level\

        for (auto i : m)
            cout << i.second << " ";
        cout << endl;
    }

    void printTopView(Node *root)
    {
        if (root == NULL)
            return;

        queue<pair<int, Node *>> q;
        map<int, int> m;

        q.push({0, root});

        while (!q.empty())
        {
            int dist = q.front().first;
            Node *p = q.front().second;

            if (m[dist] == NULL)
                m[dist] = root->val;

            if (root->left != NULL)
                q.push({dist - 1, root->left});

            if (root->right != NULL)
                q.push({dist + 1, root->right});
        }
        for (auto i : m)
            cout << i.second
                 << " ";

        cout << endl;
    }

    void convertToDLL(Node *root)
    {
        if (root == NULL)
            return;

        convertToDLL(root->left);
        if (prev == NULL)
            head = root;
        else
        {
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        convertToDLL(root->right);
    }

    int getDiameter(Node *root)
    {
        if (root == NULL)
            return 0;
        int ld = getDiameter(root->left);
        int rd = getDiameter(root->right);

        ans = max(ans, 1 + ld + rd);
        return 1 + max(ld, rd);
    }

    Node *lca(Node *root, int n1, int n2)
    {
        if (root == NULL)
            return NULL;

        if (root->val == n1 || root->val == n2)
            return root;

        Node *l = lca(root->left, n1, n2);
        Node *r = lca(root->right, n1, n2);

        if (l == NULL)
            return r;
        if (r == NULL)
            return l;

        return root;
    }
};

int main()
{
    BinaryTree *tree = new BinaryTree();
    Node *root = tree->buildTree();
    tree->inorder(root);
    cout << endl;
    tree->preorder(root);
    cout << endl;
    tree->postorder(root);
    cout << endl;
}
