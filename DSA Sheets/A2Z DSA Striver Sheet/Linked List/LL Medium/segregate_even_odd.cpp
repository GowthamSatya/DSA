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
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

class Solution
{
public:
    Node *divide(int N, Node *head)
    {
        // code here
        Node *even = NULL, *odd = NULL, *st = NULL;

        Node *p = head;

        while (p != NULL)
        {
            if (p->data & 1)
            {
                if (odd == NULL)
                {
                    odd = new Node(p->data);
                    st = odd;
                }
                else
                {
                    odd->next = new Node(p->data);
                    odd = odd->next;
                }
            }
            else
            {
                if (even == NULL)
                {
                    even = new Node(p->data);
                    head = even;
                }
                else
                {
                    even->next = new Node(p->data);
                    even = even->next;
                }
            }
            p = p->next;
        }

        if (even != NULL)
            even->next = st;
        if (even == NULL)
            return st;
        return head;
    }
};

int main()
{
    // code
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int data;
        cin >> data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N - 1; ++i)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans);
    }
    return 0;
}