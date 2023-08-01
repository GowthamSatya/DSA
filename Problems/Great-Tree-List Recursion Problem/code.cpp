// Write a recursive function treeToList(Node root) that takes an ordered binary tree and rearranges
// the internal pointers to make a circular doubly linked list out of the tree nodes. 
// The”previous” pointers should be stored in the “small” field and the “next” pointers should be 
// stored in the “large” field. The list should be arranged so that the nodes are in increasing order.
// Return the head pointer to the new list.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node *TreeToDLL(Node *root, Node **head){
    if(root == NULL) return root;

    static Node *prev = NULL;
    TreeToDLL(root->left, head);

    if(prev == NULL){
        *head= root;
    }else{
        root->left = prev;
        prev->right = root;
    }

    prev= root;
    TreeToDLL(root->right, head);
    return prev;
}

Node *TreeToCDLL(Node *root){
    Node *head = NULL;
    Node *tail = TreeToDLL(root, &head);
    tail->right= head;
    head->left = tail;

    return head;
}

void printList(Node *head){
    if(head == NULL){
        return;
    }
    Node *p = head;
    do{
        cout << p->data << " ";
        p = p->right;
    }while(p != head);
}

Node* newNode(int data)
{
    Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return (new_node);
}

int main(){
    Node *root     = newNode(10);
    root->left     = newNode(12);
    root->right     = newNode(15);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);
 
    // Convert to DLL
    Node *head = TreeToCDLL(root);
 
    // Print the converted list
    printList(head);
    return 0;
}