#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *link;
    Node()
    {
        data = 0;
        link = NULL;
    }
};

class LinkedList
{
    Node *head;
    int size;

public:
    LinkedList()
    {
        head = NULL;
        size = 0;
    }
    LinkedList(int size)
    {
        head = NULL;
        this->size = size;
    }

    void insertNode(int d)
    {
        Node *temp = new Node();
        temp->data = d;
        temp->link = NULL;

        if (head == NULL)
        {
            head = temp;
            size++;
        }
        else
        {
            Node *temp2 = head;
            while (temp2->link != NULL)
            {
                temp2 = temp2->link;
            }
            temp2->link = temp;
            size++;
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->link;
        }
        cout << endl;
    }

    void getSize()
    {
        cout << size << endl;
    }

    friend int convertDecimal(LinkedList &l);
};

int convertDecimal(LinkedList &l)
{
    int sum = 0;
    int count = l.size;
    Node *temp = l.head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            sum += 0;
            count--;
        }
        else
        {
            sum += pow(2, count - 1);
            count--;
        }
        temp = temp->link;
    }
    return sum;
}

int main()
{
    LinkedList l;

    l.insertNode(0);
    l.insertNode(0);
    l.insertNode(0);
    l.insertNode(1);
    l.insertNode(1);
    l.insertNode(0);
    l.insertNode(0);
    l.insertNode(1);
    l.insertNode(0);

    l.display();
    l.getSize();
    cout << convertDecimal(l) << endl;
}