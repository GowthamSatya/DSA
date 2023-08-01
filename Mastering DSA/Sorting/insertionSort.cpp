#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int temp = i;
        while (j >= 0 && arr[temp] < arr[j])
        {
            swap(arr[j], arr[temp]);
            j--;
            temp--;
        }
    }

    for (auto i : arr)
        cout << i << " ";
}

int main()
{
    vector<int> arr = {24, 18, 38, 43, 14, 40, 1, 54};

    selectionSort(arr);

    return 0;
}