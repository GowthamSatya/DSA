#include <bits/stdc++.h>
using namespace std;

void subset_sum(int idx, int sum, vector<int> &arr, set<int> &ans)
{
    if (idx == arr.size())
    {
        ans.insert(sum);
        return;
    }

    // pick
    subset_sum(idx + 1, sum + arr[idx], arr, ans);

    // not pick
    subset_sum(idx + 1, sum, arr, ans);
}

int main()
{
    vector<int> arr = {3, 1, 2};
    set<int> ans;
    int sum = 0;
    subset_sum(0, sum, arr, ans);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}