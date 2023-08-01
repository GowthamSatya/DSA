#include <bits/stdc++.h>
using namespace std;

void wave_traverse(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr[0].size(); i++)
    {
        if (i & 1)
            for (int j = arr.size() - 1; j >= 0; j--)
                cout << arr[j][i] << " ";
        else
            for (int j = 0; j < arr.size(); j++)
                cout << arr[j][i] << " ";
    }
}

int main()
{
    vector<vector<int>> arr = {{11, 12, 13, 14}, {15, 16, 17, 18}, {19, 20, 21, 22}};
    wave_traverse(arr);

    return 0;
}