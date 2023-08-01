#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
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
    Node *root = newNode(stoi(ip[0]));

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

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

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

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
    Node *inorder(Node *root, int t)
    {
        if (root == NULL)
            return root;

        if (root->data == t)
            return root;

        Node *t1 = inorder(root->left, t);

        if (t1)
            return t1;
        Node *t2 = inorder(root->right, t);

        return t2;
    }

    void markParents(Node *root, unordered_map<Node *, Node *> &mp, Node *target)
    {
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();

            if (curr->left)
            {
                mp[curr->left] = curr;
                q.push(curr->left);
            }

            if (curr->right)
            {
                mp[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

private:
public:
    vector<int> KDistanceNodes(Node *root, int target, int k)
    {
        // return the sorted vector of all nodes at k dist
        vector<int> ans;

        Node *tar = inorder(root, target);

        unordered_map<Node *, Node *> parentTrack;
        markParents(root, parentTrack, tar);

        unordered_map<Node *, bool> vis;
        queue<Node *> q;
        q.push(tar);
        vis[tar] = true;
        int level = 0;

        while (!q.empty())
        {
            int s = q.size();
            if (level++ == k)
                break;

            for (int i = 0; i < s; i++)
            {
                Node *curr = q.front();
                q.pop();

                if (curr->left && !vis[curr->left])
                {
                    q.push(curr->left);
                    vis[curr->left] = true;
                }

                if (curr->right && !vis[curr->right])
                {
                    q.push(curr->right);
                    vis[curr->right] = true;
                }

                if (parentTrack[curr] && !vis[parentTrack[curr]])
                {
                    q.push(parentTrack[curr]);
                    vis[parentTrack[curr]] = true;
                }
            }
        }

        while (!q.empty())
        {
            ans.push_back(q.front()->data);
            q.pop();
        }
        sort(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    getchar();

    Solution x = Solution();

    while (t--)
    {
        string s;
        getline(cin, s);
        Node *head = buildTree(s);

        int target, k;
        cin >> target >> k;
        getchar();

        vector<int> res = x.KDistanceNodes(head, target, k);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}