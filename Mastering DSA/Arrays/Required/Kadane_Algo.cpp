#include <bits/stdc++.h>
using namespace std;

int largest_subarray_sum(vector<int> &arr)
{
    int n = arr.size();

    int max_ending_here = 0;
    int max_so_far = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + arr[i];

        max_so_far = max(max_so_far, max_ending_here);

        if (max_ending_here < 0)
            max_ending_here = 0;
    }

    return max_so_far;
}

int main()
{
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};

    cout << largest_subarray_sum(arr);

    return 0;
}