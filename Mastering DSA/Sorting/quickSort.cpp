#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int lo, int hi)
{
    int pivot = arr[lo];
    int i = lo;
    int j = hi;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= hi - 1)
            i++;
        while (arr[j] > pivot && j >= lo + 1)
            j--;

        if (i < j)
            swap(arr[i], arr[j]);
    }

    swap(arr[lo], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int lo, int hi)
{
    if (lo < hi)
    {
        int pIdx = partition(arr, lo, hi);
        quickSort(arr, lo, pIdx - 1);
        quickSort(arr, pIdx + 1, hi);
    }
}

int main()
{
    vector<int> arr = {2, 3, 5, 1, 4};

    quickSort(arr, 0, 4);

    for (auto i : arr)
        cout << i << " ";

    return 0;
}