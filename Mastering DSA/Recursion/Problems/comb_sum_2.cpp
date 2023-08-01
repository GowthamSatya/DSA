#include <bits/stdc++.h>
using namespace std;

// Time Complexity =  O(2^t * k) t = len(Arr) k = mutiple picks
// Space Complexity = O(k*x)
void comb_sum(int i, int t, vector<vector<int>> &ans, vector<int> &list, vector<int> &arr)
{
    // base case
    if (t == 0)
    {
        ans.push_back(list);
        return;
    }

    for (int j = i; j < arr.size(); j++)
    {
        if (j > i && arr[j] == arr[j - 1])
            continue;
        if (t < arr[j])
            break;

        list.push_back(arr[j]);
        comb_sum(j + 1, t - arr[j], ans, list, arr);
        list.pop_back();
    }
}

int main()
{
    vector<int> arr = {1, 1, 1, 2, 2};
    int t = 4;
    vector<int> list;
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    comb_sum(0, t, ans, list, arr);

    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}