#include <bits/stdc++.h>
using namespace std;

void print_arr(vector<int> &arr)
{
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}

void k_subseq_sum(int i, vector<int> &arr, int k, int sum, vector<int> &list)
{
    // base case
    if (i == arr.size())
    {
        if (sum == k)
            print_arr(list);
        return;
    }

    list.push_back(arr[i]);
    sum += arr[i];
    k_subseq_sum(i + 1, arr, k, sum, list); // take the element
    sum -= arr[i];
    list.pop_back();
    k_subseq_sum(i + 1, arr, k, sum, list); // skip the element
}

int main()
{
    vector<int> arr = {1, 2, 1};
    int k = 2;

    vector<int> list;
    k_subseq_sum(0, arr, k, 0, list);
    return 0;
}