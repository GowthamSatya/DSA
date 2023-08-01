#include <bits/stdc++.h>
using namespace std;

void rotate_arr(vector<vector<int>> &arr)
{
    // rotate by 90 = transpose + reverse columns

    // Transpose
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr[0].size(); j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    // Reverse
    int n = arr.size();
    for (int i = 0; i < n / 2; i++)
        for (int j = 0; j < arr[0].size(); j++)
            swap(arr[j][i], arr[j][n - i - 1]);

    for (auto i : arr)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> arr = {
        {11, 12, 13, 14},
        {21, 22, 23, 24},
        {31, 32, 33, 34},
        {41, 42, 43, 44},
    };

    rotate_arr(arr);
    return 0;
}