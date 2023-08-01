#include <bits/stdc++.h>
using namespace std;

int trapped_units(vector<int> &arr)
{
    // intialize the two pointers and result array
    int lo = 0, hi = arr.size() - 1, res = 0;

    int left_m = 0, right_m = 0;

    // termiate loop if lo > hi
    while (lo <= hi)
    {
        // checking the boundaries of left and right
        if (arr[lo] <= arr[hi])
        {
            // updating the left_boundary
            if (left_m <= arr[lo])
                left_m = arr[lo];
            else
                res += (left_m - arr[lo]); // amount of water trapped
            lo++;
        }
        else
        {
            // updating the right_boundary
            if (right_m <= arr[hi])
                right_m = arr[hi];
            else
                res += (right_m - arr[hi]); // trapping the right boundary
            hi--;
        }
    }
    return res;
}

int main()
{
    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trapped_units(arr) << endl;

    return 0;
}