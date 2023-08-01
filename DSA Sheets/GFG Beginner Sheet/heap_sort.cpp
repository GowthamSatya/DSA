#include <bits/stdc++.h>
using namespace std;

/*
    Problem Statement:
    https://practice.geeksforgeeks.org/problems/heap-sort/1?page=1&curated[]=8&sortBy=submissions

    Input :
    N = 5
    arr[] = {4,1,3,9,7}

    Output: 1 3 4 7 9

    Explaination:
    After sorting elements
    using heap sort, elements will be
    in order as 1,3,4,7,9.
*/

// Heapify function to maintain heap property.
void heapify(int arr[], int n, int i)
{
    // Your Code Here
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to build a Heap from array.
void buildHeap(int arr[], int n)
{
    // Your Code Here
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

// Function to sort an array using Heap Sort.
void heapSort(int arr[], int n)
{
    buildHeap(arr, n);

    for (int i = n - 1; i >= 0; --i)
    {
        swap(arr[i], arr[0]);

        heapify(arr, i, 0);
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    heapSort(arr, n);

    return 0;
}