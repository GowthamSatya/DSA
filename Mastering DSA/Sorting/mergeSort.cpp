#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int lo, int mid, int hi)
{
    vector<int> temp;
    int l = lo;
    int r = mid + 1;

    while (l <= mid && r <= hi)
    {
        if (arr[l] < arr[r])
            temp.push_back(arr[l++]);
        else
            temp.push_back(arr[r++]);
    }

    while (l <= mid)
        temp.push_back(arr[l++]);
    while (r <= hi)
        temp.push_back(arr[r++]);

    for (int i = lo; i <= hi; i++)
        arr[i] = temp[i - lo];
}

void mergeSort(vector<int> &arr, int lo, int hi)
{
    if (lo >= hi)
        return;

    int mid = (lo + hi) / 2;

    mergeSort(arr, lo, mid);
    mergeSort(arr, mid + 1, hi);
    merge(arr, lo, mid, hi);
}

int main()
{
    vector<int> arr = {3, 2, 5, 1, 4};

    int n = arr.size();
    mergeSort(arr, 0, n - 1);

    for (auto i : arr)
        cout << i << " ";
    return 0;
}