#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/*
    Problem Statement:
    https://practice.geeksforgeeks.org/problems/node-at-a-given-index-in-linked-list/1?page=1&curated[]=8&sortBy=submissions

    Input :
    2
    6 5
    1 2 3 4 657 76
    10 2
    8 7 10 8 6 1 20 91 21 2

    Output:
    657
    7

    Explanation:
    Testcase 1: Element at 5th index in the linked list is 657 (1-based indexing).

*/

/* Link list node */
struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct node *push(struct node *head, int d)
{

    struct node *new_node =
        (struct node *)malloc(sizeof(struct node));

    new_node->data = d;
    new_node->next = NULL;

    if (head == NULL)
        return new_node;

    struct node *h = head;
    while (head->next != NULL)
        head = head->next;
    head->next = new_node;

    return h;
}

int GetNth(struct node *head, int index)
{
    node *p = head;
    while (index > 1)
    {
        p = p->next;
        index--;
    }

    return p->data;
}

/* Driver program to test above function*/
int main()
{
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif

    int T, i, n, l, k;

    cin >> T;

    while (T--)
    {
        struct node *head = NULL;

        cin >> n >> k;
        for (i = 1; i <= n; i++)
        {
            cin >> l;
            head = push(head, l);
        }

        printf("%d\n", GetNth(head, k));
        getchar();
    }
    return 0;
}