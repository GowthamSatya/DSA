#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

class CLL{
    Node *last;
    public:
    CLL(int d){
        Node *temp = new Node(d);
       last = temp;
       temp->next = last;
    }

    // to insert  node at beginning  in O(1) time
    void insertBegin(int d){
        Node *temp = new Node(d);
        temp->next = last->next;
        last->next = temp; 
    }

     // to insert  node at end of list in O(1) time
    void insertEnd(int d){
        Node *temp = new Node(d);
        temp->next = last->next;
        last->next = temp; 
        last =temp;
    }

    // to insert node in between two nodes in O(n) time
    void insertBetween(int n, int d){
        Node *p = last->next;

        do{
            if(p->data == d){
                Node *temp = new Node(d);
                temp->next = p->next;
                p->next = temp;

                if(p == last) last  =temp;
                return;
            }
            p = p->next;
        }
        while(p != last->next);

        cout << "item is not in the list" << endl;
        return;
    }

    void splitList(){
        Node *head = last->next;
        Node *fast = head;
        Node *slow = head;
        
        while(fast->next != head && fast->next->next != head){
            fast = fast->next->next;
            slow = slow->next;
        }

        if(fast->next->next == head){
            fast  =fast->next;
        }

        Node *h1 = head;
        Node *h2;
        if(head->next != head) h2=slow->next;

        fast->next = slow->next;
        slow->next = head;
    }

    void sortedInsert(int d){
        Node *p = last->next;
        if(p == NULL){
            Node *temp = new Node(d);
            last = temp;
            last->next = temp;
            temp->next= temp;
        }

        if(p->data >= d){
            while(p->next != last->next){
                p = p->next;
            }
            p->next = new Node(d);
            p->next->next = last->next;
        }
    }

    void display(){
        Node *temp = last->next;
        while(temp != last){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << last->data << endl;
    }
};

int main(){
    CLL *l = new CLL(1);
    l->insertEnd(2);
    l->insertEnd(3);
    l->display();
    return 0;
}