#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
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

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
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

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
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
    void inorder(Node *root, vector<int> &v1)
    {
        if (!root)
        {
            return;
        }
        inorder(root->left, v1);
        v1.push_back(root->data);
        inorder(root->right, v1);
        return;
    }

    // void convertDLL(Node *root, Node *head){
    //     if(root == NULL) return;

    //     convertDLL(root->right, head);
    //     root->right = head;

    //     if(head) head->left = root;

    //     head = root;
    //     convertDLL(root->left, head);
    // }

    // Node* mergeLL(Node *h1, Node* h2){
    //     Node *head = NULL;
    //     Node* tail = NULL;

    //     while(h1 && h2){
    //         if(h1->data  < h2->data){
    //             if(head == NULL){
    //                 head = h1;
    //                 tail = h1;
    //                 h1 = h2->right;
    //             }else{
    //                 tail->right = h1;
    //                 h1->left = tail;
    //                 tail = h1;
    //                 h1 = h1->right;
    //             }
    //         }else{
    //             if(head == NULL){
    //                 head = h2;
    //                 tail = h2;
    //                 h2 = h1->right;
    //             }else{
    //                  tail->right = h2;
    //                 h2->left = tail;
    //                 tail = h2;
    //                 h2 = h2->right;
    //             }
    //         }
    //     }

    //     while(h1){
    //         tail->right = h1;
    //                 h1->left = tail;
    //                 tail = h1;
    //                 h1 = h1->right;
    //     }

    //     while(h2){
    //           tail->right = h2;
    //                 h2->left = tail;
    //                 tail = h2;
    //                 h2 = h2->right;
    //     }

    //     return head;
    // }

    // int cntNodes(Node* head){
    //     int cnt = 0;
    //     Node *temp = head;
    //     while(temp){
    //         cnt++;
    //         temp =temp->next;
    //     }
    //     return cnt;
    // }

    // Node* LLtoBST(Node* &head, int n){
    //     // base
    //     if(n<= 0|| head == NULL) return NULL;

    //     Node *left = LLtoBST(head, n/2);
    //     Node *root = head;
    //     root->left = left;

    //     head=  head->right;

    //     root->right = LLtoBST(head, n-n/2-1);
    //     return root;
    // }

    vector<int> mergetwo(vector<int> v1, vector<int> v2)
    {
        vector<int> v(v1.size() + v2.size());
        int a = 0;
        int b = 0;
        int i = 0;
        while (a < v1.size() && b < v2.size())
        {
            if (v1[a] < v2[b])
            {
                v[i++] = v1[a++];
            }
            else
            {
                v[i++] = v2[b++];
            }
        }
        while (a < v1.size())
        {
            v[i++] = v1[a++];
        }
        while (b < v2.size())
        {
            v[i++] = v2[b++];
        }
        return v;
    }

public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
        // Your code here
        //   Node *head1= NULL, *head2 = NULL;
        //   convertDLL(root1, head1);
        //   head1->left = NULL;
        //   convertDLL(root2, head2);
        //   head2->left = NULL;

        //   Node *h = mergeLL(head1, head2);

        //   int cnt = cntNodes(h);
        //   return LLtoBST(h, cnt);

        vector<int> v1, v2;
        inorder(root1, v1);
        inorder(root2, v2);
        vector<int> v = mergetwo(v1, v2);
        return v;
    }
};

int main()
{

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root1 = buildTree(s);

        getline(cin, s);
        Node *root2 = buildTree(s);

        // getline(cin, s);
        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
        /// cout<<"~"<<endl;
    }
    return 0;
}