#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int mini = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[mini])
                mini = j;
        }

        swap(arr[i], arr[mini]);
    }

    for (auto i : arr)
        cout << i << " ";
}

int main()
{
    vector<int> arr = {4, 1, 3, 9, 7};

    selectionSort(arr);
    return 0;
}