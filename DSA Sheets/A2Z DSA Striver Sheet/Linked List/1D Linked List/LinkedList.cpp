#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class LinkedList
{
    Node *head;

public:
    // constructor
    LinkedList()
    {
        this->head = NULL;
    }

    // insert a node at the head of the linked list
    void insertBegin(int val)
    {
        Node *temp = new Node(val);

        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            Node *p = head;
            head = temp;
            head->next = p;
        }
    }
    // TC -> O(1)

    // insert a new Node
    void insert(int val)
    {
        Node *temp = new Node(val);
        if (head == NULL)
            head = temp;
        else
        {
            Node *p = head;
            while (p->next != NULL)
                p = p->next;
            p->next = temp;
        }
    }
    // TC -> O(N)

    // delete a Node from linked list
    void deleteNode(int pos)
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

    // reverse the linked list
    Node *reverse()
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

    Node *reverseRec(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        Node *newHead = reverseRec(head->next);
        Node *nextHead = head->next;
        nextHead->next = head;
        head->next = NULL;

        return newHead;
    }

    // search for the value in the linked list
    int search(int val)
    {
        Node *p = head;
        while (p != NULL)
        {
            if (p->val == val)
                return 1;
            p = p->next;
        }

        return 0;
    }
    // TC -> O(N)

    // get the length of linked list
    int getLength()
    {
        Node *p = head;
        int cnt = 0;

        while (p != NULL)
        {
            cnt++;
            p = p->next;
        }
        return cnt;
    }

    // Display the linked list
    void display()
    {
        Node *p = head;
        while (p != NULL)
        {
            if (p->next != NULL)
                cout << p->val << "->";
            else
                cout << p->val << endl;
            p = p->next;
        }
    }
};

int main()
{
}