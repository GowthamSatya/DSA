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

Node *reverseKGroup(Node *head, int k)
{
    if (head == NULL || k == 1)
        return head;

    Node *dummy = new Node(0);
    dummy->next = head;

    Node *p = dummy, *curr = dummy, *prev = dummy;
    int cnt = 0;

    while (p)
    {
        p = p->next;
        cnt++;
    }

    while (cnt >= k)
    {
        p = prev->next;
        curr = p->next;

        for (int i = 1; i < k; i++)
        {
            p->next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
            curr = p->next;
        }

        prev = p;
        cnt -= k;
    }

    return dummy->next;
}
