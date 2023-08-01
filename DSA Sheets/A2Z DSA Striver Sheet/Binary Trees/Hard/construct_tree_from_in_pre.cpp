//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printPostOrder(Node *root)
{
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution
{
public:
    Node *solve(int in[], int is, int ie, int pre[], int ps, int pe)
    {
        if (is > ie || ps > pe)
            return NULL;
        Node *root = new Node(pre[ps]);
        int ele;
        for (int i = is; i <= ie; i++)
        {
            if (in[i] == root->data)
            {
                ele = i;
                break;
            }
        }
        int nums = ele - is;
        root->left = solve(in, is, ele - 1, pre, ps + 1, ps + nums);
        root->right = solve(in, ele + 1, ie, pre, ps + nums + 1, pe);
        return root;
    }
    Node *buildTree(int in[], int pre[], int n)
    {
        // Code here
        Node *root = solve(in, 0, n - 1, pre, 0, n - 1);
        return root;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int inorder[n], preorder[n];
        for (int i = 0; i < n; i++)
            cin >> inorder[i];
        for (int i = 0; i < n; i++)
            cin >> preorder[i];
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder, n);
        printPostOrder(root);
        cout << endl;
    }
}