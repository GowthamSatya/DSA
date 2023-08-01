#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define MAX_TREE_HT 100

struct minheapNode
{
    char input;
    int frequency;

    struct minheapNode *left, *right;
};

struct minH
{
    int size;
    int capacity;
    struct minheapNode **array;
};

struct minheapNode *createNode(char inp, int freq)
{
    struct minheapNode *temp = (struct minheapNode *)malloc(sizeof(struct minheapNode));

    temp->left = temp->right = NULL;
    temp->input = inp;
    temp->frequency = freq;

    return temp;
}

struct minH *createMinHeap(int capacity)
{
    struct minH *newHeap = (struct minH *)malloc(sizeof(struct minH));

    newHeap->size = 0;
    newHeap->capacity = capacity;
    newHeap->array = (struct minheapNode **)malloc(newHeap->capacity * sizeof(struct minheapNode));

    return newHeap;
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        cout << arr[i];

    cout << "\n";
}

void swapMinHNode(struct minheapNode **a, struct minheapNode **b)
{
    struct minheapNode *t = *a;
    *a = *b;
    *b = t;
}

void heapify(struct minH *minheap, int idx)
{
    int smallest = idx;
    int left = 2 * idx - 1;
    int right = 2 * idx + 1;

    if (left < minheap->size && minheap->array[left]->frequency < minheap->array[smallest]->frequency)
        smallest = left;
    if (right < minheap->size && minheap->array[right]->frequency < minheap->array[smallest]->frequency)
        smallest = right;

    if (smallest != idx)
    {
        swapMinHNode(&minheap->array[smallest], &minheap->array[idx]);
        heapify(minheap, smallest);
    }
}

int checkSizeOne(struct minH *minHeap)
{
    return (minHeap->size == 1);
}

struct minheapNode *extractMin(struct minH *minHeap)
{
    struct minheapNode *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    heapify(minHeap, 0);
    return temp;
}

void insertminHeap(struct minH *minHeap, struct minheapNode *node)
{
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && node->frequency < minHeap->array[(i - 1) / 2]->frequency)
    {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = node;
}

void buildMinHeap(struct minH *minHeap)
{
    int n = minHeap->size - 1;

    for (int i = (n - 1) / 2; i >= 0; --i)
    {
        heapify(minHeap, i);
    }
}

int isLeaf(struct minheapNode *node)
{
    return !(node->left) && !(node->right);
}

struct minH *createAndBuildMinHeap(char item[], int freq[], int size)
{
    struct minH *minHeap = createMinHeap(size);
    for (int i = 0; i < size; i++)
    {
        minHeap->array[i] = createNode(item[i], freq[i]);
    }
    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}

struct minheapNode *buildHfTree(char item[], int freq[], int size)
{
    struct minheapNode *left, *right, *top;
    struct minH *minHeap = createAndBuildMinHeap(item, freq, size);

    while (!checkSizeOne(minHeap))
    {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = createNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;

        insertminHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

void printHuffmanCodes(struct minheapNode *root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top + 1);
    }

    if (root->right)
    {
        arr[top] = 1;
        printHuffmanCodes(root->right, arr, top + 1);
    }

    if (isLeaf(root))
    {
        cout << root->input << " |";
        printArray(arr, top);
    }
}

void huffmanCodes(char item[], int freq[], int size)
{
    struct minheapNode *root = buildHfTree(item, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    printHuffmanCodes(root, arr, top);
}

int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Char | Huffman code ";
    cout << "\n----------------------\n";
    huffmanCodes(arr, freq, size);
}