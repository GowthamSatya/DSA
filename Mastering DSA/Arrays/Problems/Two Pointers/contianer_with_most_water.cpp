#include <bits/stdc++.h>
using namespace std;

int most_water(vector<int> &arr)
{
    int max_w = INT_MIN;
    int lo = 0, hi = arr.size() - 1;

    // brute force algo TC=> O(n^2)
    // for (int i = 0; i < arr.size() - 1; i++)
    // {
    //     for (int j = i + 1; j < arr.size(); j++)
    //     {
    //         max_w = max(max_w, (min(arr[i], arr[j]) * (j - i)));
    //     }
    // }

    while (lo <= hi)
    {
        if (arr[lo] < arr[hi])
        {
            max_w = max(max_w, (min(arr[lo], arr[hi]) * (hi - lo)));
            lo++;
        }
        else
        {
            max_w = max(max_w, (min(arr[hi], arr[lo]) * (hi - lo)));
            hi--;
        }
    }
    return max_w;
}

int main()
{
    vector<int> arr = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << most_water(arr) << endl;
    return 0;
}