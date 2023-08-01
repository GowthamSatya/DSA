//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
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

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    Node *reverse(Node *head)
    {
        Node *prev = NULL, *curr = head;

        while (curr != NULL)
        {
            Node *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }

public:
    // Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        // code here
        Node *dmm = new Node(0);
        Node *t = dmm;

        Node *l1 = reverse(first);
        Node *l2 = reverse(second);

        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry)
        {
            int sum = 0;

            if (l1)
            {
                sum += l1->data;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->data;
                l2 = l2->next;
            }

            sum += carry;

            int md = sum % 10;
            carry = sum / 10;
            Node *newNode = new Node(md);

            t->next = newNode;
            t = t->next;
        }
        dmm->next = reverse(dmm->next);

        return dmm->next;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *first = buildList(n);

        cin >> m;
        Node *second = buildList(m);
        Solution ob;
        Node *res = ob.addTwoLists(first, second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends