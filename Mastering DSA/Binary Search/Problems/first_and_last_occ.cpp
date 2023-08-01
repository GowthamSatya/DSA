#include <bits/stdc++.h>
using namespace std;

int get_first_occurrence(vector<int> &arr, int key)
{
    int lo = 0;
    int hi = arr.size() - 1;

    int mid = lo + (hi - lo) / 2;
    int ans = 0;
    while (lo <= hi)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            hi = mid - 1;
        }

        if (key > arr[mid])
        {
            lo = mid + 1;
        }

        if (key < arr[mid])
        {
            hi = mid - 1;
        }

        mid = lo + (hi - lo) / 2;
    }
    return ans;
}

int get_last_occurrence(vector<int> &arr, int key)
{
    int lo = 0;
    int hi = arr.size() - 1;

    int mid = lo + (hi - lo) / 2;
    int ans = 0;
    while (lo <= hi)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            lo = mid + 1;
        }

        if (key > arr[mid])
        {
            lo = mid + 1;
        }

        if (key < arr[mid])
        {
            hi = mid - 1;
        }

        mid = lo + (hi - lo) / 2;
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 3, 5};

    int i1 = get_first_occurrence(arr, 3);
    int i2 = get_last_occurrence(arr, 3);

    cout << i1 << " " << i2 << endl;

    return 0;
}