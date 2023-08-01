#include <bits/stdc++.h>
using namespace std;

void print_arr(vector<int> &arr)
{
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}

// Time Complexity =  O(2^t * k) t = len(Arr) k = mutiple picks
// Space Complexity = O(k*x)
void comb_sum(int i, int t, vector<int> &list, vector<int> &arr)
{
    // base case
    if (i == arr.size())
    {
        if (t == 0)
            print_arr(list);
        return;
    }

    if (arr[i] <= t)
    {
        list.push_back(arr[i]);
        // pick the element(mulitple times)
        comb_sum(i, t - arr[i], list, arr);
        list.pop_back();
    }
    comb_sum(i + 1, t, list, arr); // not pick the element
}

int main()
{
    vector<int> arr = {2, 3, 6, 7};
    int t = 7;
    vector<int> list;
    comb_sum(0, t, list, arr);
    return 0;
}