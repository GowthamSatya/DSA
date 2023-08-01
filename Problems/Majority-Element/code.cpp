#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findMajority(int arr[], int n)
{
    map<int, int> hash;
    for (int i = 0; i < n; i++)
    {
        cout << hash[arr[i]] << " ";
        hash[arr[i]]++;
    }
    for (auto i : hash)
    {
        if (i.second > n / 2)
        {
            return i.first;
        }
    }

    return 0;
}

int main()
{
    int arr[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findMajority(arr, n);
}