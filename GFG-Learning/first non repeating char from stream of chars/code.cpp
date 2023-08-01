#include <iostream>
#include <bits/stdc++.h>
#define MAX_CHAR 256
using namespace std;

struct Node{
    char data;
    struct Node *next, *prev;
};

void appendNode(struct Node **head,struct Node **tail, char x){
    struct Node *temp = new Node;
    temp->data =x;
    temp->next = NULL; temp->prev = NULL;

    if(*head==NULL){
        *head = *tail = temp;
        return;
    }
    (*tail)->next = temp;
    temp->prev = *tail;
    *tail = temp;
}

void removeNode(struct Node** head_ref,
                struct Node** tail_ref, struct Node* temp)
{
    if (*head_ref == NULL)
        return;
  
    if (*head_ref == temp)
        *head_ref = (*head_ref)->next;
    if (*tail_ref == temp)
        *tail_ref = (*tail_ref)->prev;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
  
    delete (temp);
}

void firstNonRepaeating(){
    bool repeated[MAX_CHAR];
    struct Node* inDLL[MAX_CHAR];

    struct Node *head = NULL, *tail =NULL;
    for (int i = 0; i < MAX_CHAR; i++){
        inDLL[i] = NULL;
        repeated[i] = false;
    }

    char stream[] = "geeksforgeeks";
    for(int i=0;stream[i];i++){
        char x = stream[i];
        cout<< "Reading "<<x<<" from stream\n"<<endl;  

        if(!repeated[x]){
            if(inDLL[x] == NULL){
                appendNode(&head,&tail,stream[i]);
                inDLL[x] = tail;
            }else{
                removeNode(&head,&tail,inDLL[x]);
                inDLL[x] = NULL;
                repeated[x] =true;
            }
        }

        if(head != NULL){
            cout << "first non repeating char is " << head->data<< endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    firstNonRepaeating();
}