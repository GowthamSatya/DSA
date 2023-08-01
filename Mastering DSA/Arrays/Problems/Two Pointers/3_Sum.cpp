#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> three_sum(vector<int> &arr)
{
    sort(arr.begin(), arr.end());

    vector<vector<int>> res;

    for (int i = 0; i < arr.size() - 2; i++)
    {
        if (i == 0 || (i > 0 && arr[i] != arr[i - 1]))
        {
            int lo = i + 1;
            int hi = arr.size() - 1;
            int sum = 0 - arr[i];

            while (lo < hi)
            {
                int temp = arr[lo] + arr[hi];
                if (temp == sum)
                {
                    res.push_back({arr[i], arr[lo], arr[hi]});
                    while (lo < hi && arr[lo + 1] == arr[lo])
                        lo++;
                    while (lo < hi && arr[hi] == arr[hi - 1])
                        hi--;
                    lo++;
                    hi--;
                }
                else if (arr[lo] + arr[hi] < sum)
                    lo++;
                else
                    hi--;
            }
        }
    }
    return res;
}

int main()
{
    vector<int> arr = {-2, -2, -1, -1, -1, 0, 0, 0, 2, 2, 2};
    vector<vector<int>> s = three_sum(arr);

    for (auto i : s)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}