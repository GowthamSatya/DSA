#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    vector<int> arr = {8, 10, 17, 1, 5};

    cout << get_pivot_idx(arr) << endl;

    return 0;
}