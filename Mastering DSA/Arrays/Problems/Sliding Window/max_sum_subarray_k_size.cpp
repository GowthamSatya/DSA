#include <bits/stdc++.h>
using namespace std;

int max_subarray_sum(vector<int> &arr, int k)
{
    // init two pointers
    int st = 0;
    int end = k - 1;

    if (k > arr.size())
        return -1;

    int max_sum = 0, sum = 0;

    // sum of first window
    for (int i = st; i <= end; i++)
        max_sum += arr[i];

    sum += max_sum;

    // calculate sum of next windows and update max sum
    while (end != arr.size() - 1)
    {
        end++;
        sum += arr[end] - arr[st];
        max_sum = max(max_sum, sum);
        st++;
    }
    return max_sum;
}

int main()
{
    vector<int> arr = {100, 200, 300, 400};
    int k = 2;

    cout << max_subarray_sum(arr, k) << endl;
    return 0;
}