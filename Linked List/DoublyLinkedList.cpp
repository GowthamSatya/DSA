#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next, *prev;
    Node(int d){
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class DLL{
    Node *head;
    public:
    DLL(int d){
        head = new Node(d);
        head->next = NULL;
        head->prev = NULL;
    }

    void insertAtFront(int d){
        Node *n = new Node(d);
        n->next = head;
        n->prev = NULL;
        head->prev = n;
        head = n;
    }

    void insertAtBack(int d){
        Node *n = new Node(d);
        Node *p = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = n;
        n->prev = p;
        n->next = NULL;
    }

    void insertAfter(int n, int d){
        Node *temp = new Node(d);
        Node *p = head;
        while(p != NULL and p->data == n){
            p = p->next;
        }
        p = p->next;
        if(p == NULL){
            cout << "Node not found" << endl;
            return;
        }
        temp->next = p->next;
        p->next = temp;
          temp->prev = p;
          if(temp->next !=NULL) 
        temp->next->prev = temp;
      
        
    }

    void deleteNode(int d){
        Node *p = head;
        if(p->data == d){
            head = p->next;
        }

        while(p->next != NULL and p->data != d){
            p = p->next;
        }

        if(p->next != NULL){
            p->next->prev= p->prev;
        }
        
        if(p->prev!= NULL){
            p->prev->next= p->next;
        }
        delete p;
        return;
    }

    void reverse(){
        Node *temp = NULL;
        Node *c = head;

        while(c != NULL){
            temp = c->prev;
            c->prev = c->next;  
            c->next = temp;
            c = c->prev;
        }

        if(temp != NULL){
            head = temp->prev; 
        }
    }

    void display(){
        Node *p= head;
        while(p!= NULL){
            cout << p->data << "<->";
            p = p->next;
        }
        cout << "NULL" << endl;
    }


    friend Node *lastnode(DLL *);
    friend void quicksort(DLL *);
};

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b= temp;
}

Node *lastnode(DLL *l){
    Node *p = l->head;
    while(p and p->next){
        p= p->next;
    }
    return p;
}

Node *partition(Node *l, Node *h){
    if(l==NULL or h==NULL) return NULL;
    int x = h->data; // pivot element
    Node *i = l->prev;

    for(Node *j=l;j!=h;j=j->next){
        if(j->data <= x){
            i = (i==NULL)? l : i->next;
            swap(&(i->data), &(j->data));
        }       
    }
    i= (i== NULL) ? l : i->next;
    swap(&(i->data), &(h->data));
    return i;
}

void _quicksort(Node *l, Node *h){
    if(h != NULL and l!=h and l!=h->next){
        Node *p = partition(l,h);
        _quicksort(l,p->prev);
        _quicksort(p->next,h);
    }
}

void quicksort(DLL *l){
    Node *h = lastnode(l);
    _quicksort(l->head,h);
}

int main(){
    DLL *d1 = new DLL(2);
    d1->insertAtFront(1);
    d1->insertAtFront(3);
    d1->insertAtFront(4);
    d1->insertAtBack(5);
    d1->insertAfter(3,6);
    d1->display();
    d1->deleteNode(5);
    d1->display();
    d1->reverse();
    d1->display();
    quicksort(d1);
    d1->display();
}