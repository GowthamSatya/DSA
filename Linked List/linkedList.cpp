#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Time Complexity :
    // Insertion : O(n)
    // Deletion : O(n)
    // Search : O(n)

class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

class LinkedList{
    Node *head;
    public:
    LinkedList(int d){
        head = new Node(d);
    }

    ~LinkedList(){
        delete head;
    }

    void insert(int d){
        Node *p = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = new Node(d);
    }

    void deleteNode(int d){
        Node *p = head;
        if(p->data == d){
            head = p->next;
            return;
        }
        Node *temp;
        while(p!= NULL){
            if(p->next->data == d){
               temp = p->next;
                break;
            }
            p = p->next;
        }
        p->next = temp->next;
    }

    void getLength(){
        Node *p = head;
        int c = 0;
        while(p != NULL){
            c++;
            p = p->next;
        }

        cout << c << endl;
    }

    // Given a linked list and two keys in it, swap nodes for two given keys. Nodes should be swapped by changing links.
    void swapNodes(int n1, int n2){
        Node *prevA =NULL, *currA = head;
        // get current pos of n1 and its prev node
        while(currA && currA->data != n1){
            prevA = currA;
            currA = currA->next;
        } 

        // get current pos of n2 and its prev node
        Node *prevB =NULL, *currB = head;
        while(currB && currB->data != n2){
            prevB = currB;
            currB = currB->next;
        } 

        // Either n1 or n2 is not present in linked list
        if(currA == NULL || currB == NULL) return;

        // if n1 is not head
        if(prevA != NULL) prevA->next = currB;
        else head = currB;

         // if n2 is not head
        if(prevB != NULL) prevB->next = currA;
        else head = currA;

        Node *temp = currB->next;
        currB->next = currA->next;
        currA->next = temp;
    }

    void reverse(){
        Node *prev = NULL;
        Node *curr = head;
        Node *p = NULL;
        while(curr != NULL){
             p = curr->next;
            curr->next= prev;
            prev = curr;
           
            curr = p;
        }

        head= prev;
    }

    LinkedList *merge(LinkedList *l){
        Node *a, *b;
        a = head;
        b = l->head;
        LinkedList *merged;
        Node *p = head;
        Node *q = l->head;
        if(p == NULL) return l;
        else if(q == NULL) return this;
        else{
            if( a->data >= b->data){
                merged = new LinkedList(b->data);
                b= b->next;
            
            }else{
              
               merged = new LinkedList(a->data);
                a = a->next;
      
            }
            Node *m = merged->head;
            while(a->next != NULL || b->next!=NULL){
                if( a->data >= b->data){
                    m->next = b;
                    b= b->next;
                }else{
                    m->next = a;
                    a = a->next;
                }
                m = m->next;
           }
            
        }
        return merged;
    }

    void reverseGroup(int k){
        if(!head) return;
        Node *dummy = new Node(-1);
        dummy->next =head;

        Node *prev = dummy, *p = dummy, *curr = dummy;
        int c=0;
        while(curr){
            curr = curr->next;
            c++;
        }

        while(p){
            curr = prev->next;
            p = curr->next;

            int toL = c > k ? k : c-1;
            for(int i=1;i<toL;i++){
                curr->next = p->next;
                p->next = prev->next;
                prev->next = p;
                p = curr->next;
            }

            prev= curr;
            c -=k;
        }
        display();
    }

    // Floyd's Cycle Detection algorithm (Optimised)
    int detectAndRemoveLoop(){
        if(head == NULL || head->next == NULL) return 0;

        //start slow and fast from head
        Node *slow= head, *fast=head;

        // move slow one point forward and fast two points forward
        slow = slow->next;
        fast = fast->next->next;

        // loop until slow and fast meet or fast becomes null
        while(fast && fast->next){
            if(slow == fast) break;
            slow = slow->next;
            fast = fast->next->next;
        }
    
        // if loop is present
        if(slow == fast){
            slow = head;

            if(slow == fast){
                // if loop starts from head itself
                while(fast->next != slow) fast = fast->next;
            }else{
                // to find the node where the loop is present
                while(slow->next != fast->next){
                    slow = slow->next;
                    fast = fast->next;
                }
        }
        // removing the loop by making next pointer null
        fast->next = NULL;
        }
    }

    LinkedList *findSum(LinkedList *l){
        Node *res = NULL;
        Node *temp, *prev = NULL;
        reverse();
        l->reverse();
        Node *f= head;
        Node *s = l->head;
        int c=0,sum=0;

        while(f != NULL || s!= NULL){
            // add first nodes of both lists to sum
            sum = c + (f ? f->data : 0) + (s ? s->data : 0);
            // check if sum > 10 and increment carry
            c = (sum >= 10) && 1;
            // extract first digit from sum
            sum = sum%10;   

            // create new node for sum data
            temp = new Node(sum);

            // if it is first digits to add
            if(res == NULL) res = temp;
            else prev->next = temp;

            // set prev to temp
            prev = temp;
            if(f) f= f->next;
            if(s) s= s->next;
        }   
    
        if(c>0) temp->next = new Node(c);
        LinkedList *l2 = new LinkedList(res->data);
        l2->head = res;
        l2->reverse();
        return l2;
    }

    void rotate(int k){
        Node *temp = head;
        Node *p = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next =head;
        while(temp != NULL and k>1){
            temp = temp->next;
            k--;
        }
        head= temp->next;
        temp->next = NULL;
    }

    void display(){
        Node *p = head;
        while(p != NULL){
            cout << p->data << "->";
            if(p->next == NULL){
                cout << "NULL";
            }
            p = p->next;
        }
        cout << endl;
    }
};

int main(){
    LinkedList *l1 = new LinkedList(1);
    l1->insert(2);
    l1->insert(5);
    l1->display();
     l1->rotate(1);
    l1->display();
    LinkedList *l2 = new LinkedList(3);
    l2->insert(7);
    l2->insert(5);
    LinkedList *l3;
    l3 = l1->findSum(l2);
    l3->display();
   
}