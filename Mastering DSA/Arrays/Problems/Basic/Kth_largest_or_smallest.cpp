#include <bits/stdc++.h>
using namespace std;

int kth_smallest(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());

    return arr[k - 1];
}

int main()
{
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    cout << kth_smallest(arr, 3);
    return 0;
}