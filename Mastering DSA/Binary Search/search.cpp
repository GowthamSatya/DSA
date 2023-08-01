#include <bits/stdc++.h>
using namespace std;

void binary_search(vector<int> &arr, int key)
{
    int lo = 0;
    int hi = arr.size() - 1;

    int mid = lo + (hi - lo) / 2;

    while (lo <= hi)
    {
        if (arr[mid] == key)
        {
            cout << "Key Found at position : " << lo + 1 << endl;
            return;
        }

        if (key > arr[mid])
            lo = mid + 1;
        if (key < arr[mid])
            hi = mid - 1;

        mid = lo + (hi - lo) / 2;
    }

    cout << "Key Not Found" << endl;
}

int main()
{
    vector<int> even = {2, 3, 6, 11, 12, 15};
    vector<int> odd = {5, 6, 7, 11, 13, 21, 22};

    binary_search(even, 11);
    binary_search(odd, 12);

    return 0;
}