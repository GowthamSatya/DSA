#include <bits/stdc++.h>
using namespace std;

void rearrange(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        if (!(i & 1))
        {
            if (arr[i] > arr[i - 1])
                swap(arr[i], arr[i - 1]);
        }
        else
        {
            if (arr[i] < arr[i - 1])
                swap(arr[i], arr[i - 1]);
        }
    }

    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 3, 5, 1, 2};
    rearrange(arr);
    return 0;
}