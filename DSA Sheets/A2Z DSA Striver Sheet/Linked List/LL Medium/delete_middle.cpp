//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* Function to get the middle of the linked list*/
struct Node *deleteMid(struct Node *head);
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int data;
        cin >> data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        head = deleteMid(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends

/* Link list Node:

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

int getMiddlePos(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    int pos = 1;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        pos++;
    }

    if (fast->next == NULL)
        return pos;
    return pos + 1;
}

void deleteNode(Node *head, int pos)
{
    int k = pos;

    // first element case
    if (pos == 1)
    {
        head = head->next;
        return;
    }
    Node *p = head;
    Node *q = p->next;

    while (q != NULL && k-- > 2)
    {
        p = p->next;
        q = q->next;
    }

    if (p != NULL && q != NULL)
    {
        p->next = q->next;
        q->next = NULL;
    }

    return;
}

// Deletes middle of linked list and returns head of the modified list
Node *deleteMid(Node *head)
{
    // Your Code Here
    int mid = getMiddlePos(head);
    deleteNode(head, mid);

    return head;
}