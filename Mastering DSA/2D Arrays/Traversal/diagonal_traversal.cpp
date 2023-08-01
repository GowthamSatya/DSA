#include <bits/stdc++.h>
using namespace std;

void diag_traverse(vector<vector<int>> &arr)
{
    for (int g = 0; g < arr.size(); g++)
    {
        for (int i = 0, j = g; j < arr[0].size(); i++, j++)
        {
            cout << arr[i][j] << " ";
        }
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> arr = {
        {11, 12, 13, 14, 15},
        {21, 22, 23, 24, 25},
        {31, 32, 33, 34, 35},
        {41, 42, 43, 44, 45},
        {51, 52, 53, 54, 55},
    };

    diag_traverse(arr);

    return 0;
}