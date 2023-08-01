#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &arr, int key, int st, int end)
{
    int lo = st;
    int hi = end;

    int mid = lo + (hi - lo) / 2;

    while (lo <= hi)
    {
        if (arr[mid] == key)
        {
            return lo;
        }

        if (key > arr[mid])
            lo = mid + 1;
        if (key < arr[mid])
            hi = mid - 1;

        mid = lo + (hi - lo) / 2;
    }
    return -1;
}

int get_pivot_idx(vector<int> &arr)
{
    int lo = 0;
    int hi = arr.size() - 1;

    int mid = lo + (hi - lo) / 2;

    while (lo < hi)
    {
        if (arr[mid] >= arr[0])
        {
            lo = mid + 1;
        }
        else
            hi = mid;

        mid = lo + (hi - lo) / 2;
    }
    return lo;
}

int find_element(vector<int> &arr, int key)
{
    int p_idx = get_pivot_idx(arr);

    if (key >= arr[p_idx] && key <= arr[arr.size() - 1])
        return binary_search(arr, key, p_idx, arr.size() - 1);
    else
        return binary_search(arr, key, 0, p_idx - 1);
}

int main()
{
    vector<int> arr = {12, 15, 3, 6, 8};

    cout << find_element(arr, 15) << endl;

    return 0;
}