#include <bits/stdc++.h>
using namespace std;

void rearrange(vector<int> &arr)
{
    int n = arr.size();
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        if (arr[left] < 0 and arr[right] < 0)
            left++;
        else if (arr[left] > 0 and arr[right] < 0)
        {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
        else if (arr[left] < 0 and arr[right] > 0)
        {
            left++;
            right--;
        }
        else
            right--;
    }

    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}

int main()
{
    vector<int> arr = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    rearrange(arr);
    return 0;
}