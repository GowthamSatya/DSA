#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
// User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
    Node *inorder(Node *root, int target)
    {
        if (root == NULL)
            return root;

        if (root->data == target)
            return root;

        Node *t1 = inorder(root->left, target);
        if (t1)
            return t1;

        Node *t2 = inorder(root->right, target);
        return t2;
    }

    void getParents(Node *root, unordered_map<Node *, Node *> &mp)
    {
        queue<Node *> q;

        q.push(root);

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            if (curr->left)
            {
                q.push(curr->left);
                mp[curr->left] = curr;
            }

            if (curr->right)
            {
                q.push(curr->right);
                mp[curr->right] = curr;
            }
        }
    }

public:
    int minTime(Node *root, int target)
    {
        // Your code goes here
        int time = -1;
        unordered_map<Node *, Node *> parents;
        getParents(root, parents);

        Node *tar = inorder(root, target);

        queue<Node *> q;
        unordered_map<Node *, bool> vis;

        q.push(tar);
        vis[tar] = true;

        while (!q.empty())
        {
            int s = q.size();
            time++;
            for (int i = 0; i < s; i++)
            {
                Node *t = q.front();
                q.pop();

                if (t->left && !vis[t->left])
                {
                    q.push(t->left);
                    vis[t->left] = true;
                }
                if (t->right && !vis[t->right])
                {
                    q.push(t->right);
                    vis[t->right] = true;
                }
                if (parents[t] && !vis[parents[t]])
                {
                    q.push(parents[t]);
                    vis[parents[t]] = true;
                }
            }
        }

        return time;
    }
};

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc--)
    {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();
    }

    return 0;
}