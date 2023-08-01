#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int flag = 1;
        for (int j = 1; j < n; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                flag = 0;
            }
        }

        if (flag)
            break;
    }

    for (auto i : arr)
        cout << i << " ";
}

int main()
{
    vector<int> arr = {2, 1, 4, 3, 5};

    bubbleSort(arr);
    return 0;
}