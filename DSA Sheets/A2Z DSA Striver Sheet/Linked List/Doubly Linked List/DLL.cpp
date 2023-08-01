#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node *prev;

    Node(int val) : val(val)
    {
    }
};

class DLL
{
    Node *head;

public:
    DLL()
    {
        this->head = NULL;
    }

    // insert a node at the head of the DLL
    void insertBeg(int val)
    {
        Node *temp = new Node(val);

        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            head->prev = temp;
            temp->next = head;
            temp->prev = NULL;
            head = temp;
        }
    }

    // insert at the end of linked list
    void insertEnd(int val)
    {
        Node *temp = new Node(val);

        if (head == NULL)
            head = temp;
        else
        {
            Node *p = head;
            while (p->next != NULL)
            {
                p = p->next;
            }

            p->next = temp;
            temp->prev = p;
            temp->next = NULL;
        }
    }

    // insert the node at given pos
    void insertAtPos(int val, int pos)
    {
        Node *temp = new Node(val);

        Node *p = head;

        while (p != NULL && pos > 1)
        {
            pos--;
            p = p->next;
        }

        temp->next = p->next;
        p->next = temp;
        temp->prev = p;
        temp->next->prev = temp;
    }

    // delete a node at given position in LL
    void deleteNode(int pos)
    {
        Node *p = head;

        while (p != NULL && pos > 1)
        {
            pos--;
            p = p->next;
        }

        if (p->next != NULL)
            p->next->prev = p->prev;

        if (p->prev != NULL)
            p->prev->next = p->next;
        p->next = NULL;
        p->prev = NULL;
    }

    // search in DLL
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
    // display DLL
    void
    display()
    {
        Node *p = head;
        while (p != NULL)
        {
            if (p->next != NULL)
                cout << p->val << "<->";
            else
                cout << p->val << endl;
            p = p->next;
        }
    }

    // get the length of DLL
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

    // rotate the DLL by K node
    void rotatebyK()
    {
    }

    // reverse the DLL
    void reverse()
    {
        Node *p = head;
        Node *q = p->next;

        p->next = NULL;
        p->prev = q;

        while (q != NULL)
        {
            q->prev = q->next;
            q->next = p;
            p = q;
            q = q->prev;
        }

        head = p;
    }
};

int main()
{
}