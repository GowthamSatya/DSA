#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left, *right;
};

struct node *newNode(int d){
    struct node* temp =new node;
    temp->data = d;
    temp->left = NULL;
    temp->right= NULL;
    return temp;
}

void printLevelOrder(struct node *root){
    queue<node *> q;
    q.push(root);

    while(!q.empty()){
        node *t = q.front();
        cout << t->data << " ";
        q.pop();
        if(t->left !=NULL) q.push(t->left);
        if(t->right !=NULL) q.push(t->right);
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    printLevelOrder(root);
}