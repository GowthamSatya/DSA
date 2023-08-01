#include <bits/stdc++.h>
using namespace std;

/*
    Given a sorted array
    rearrange it in the form
    max1,min1,max2,min2....
    such that
    max1>max2>... and min1<min2<...
*/

void rearrange(vector<int> &arr)
{
    int n = arr.size();

    // initialize i,min,max, M
    // M is number greater than max value of array

    int i = 0, min = 0, max = n - 1, M = arr[n - 1] + 1;

    for (int i = 0; i < n; i++)
    {
        if (i & 1)
        {
            // formula used to store the values of array odd indices
            arr[i] = arr[i] + ((arr[min] % M) * M);
            min++;
        }
        else
        {
            // formula used to store the values of array even indices
            arr[i] = arr[i] + ((arr[max] % M) * M);
            max--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] /= 7;
    }

    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    rearrange(arr);

    return 0;
}