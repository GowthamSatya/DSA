#include <bits/stdc++.h>
using namespace std;

void spiral_traversal(vector<vector<int>> &arr)
{
    int minr = 0, minc = 0;
    int maxr = arr.size() - 1, maxc = arr[0].size() - 1;

    int total = (maxr + 1) * (maxc + 1);
    int cnt = 1;

    while (cnt < total)
    {
        // left wall
        for (int i = minr, j = minc; i <= maxr; i++)
        {
            cout << arr[i][j] << " ";
            cnt++;
        }
        minc++;

        // bottom wall
        for (int i = maxr, j = minc; j <= maxc; j++)
        {
            cout << arr[i][j] << " ";
            cnt++;
        }
        maxr--;

        // right wall
        for (int i = maxr, j = maxc; i >= minr; i--)
        {
            cout << arr[i][j] << " ";
            cnt++;
        }
        maxc--;

        // top wall
        for (int i = minr, j = maxc; j >= minc; j--)
        {
            cout << arr[i][j] << " ";
            cnt++;
        }
        minr++;
    }
}

int main()
{
    vector<vector<int>> arr = {
        {11, 12, 13, 14, 15, 16, 17},
        {21, 22, 23, 24, 25, 26, 27},
        {31, 32, 33, 34, 35, 36, 37},
        {41, 42, 43, 44, 45, 46, 47},
        {51, 52, 53, 54, 55, 56, 57},
    };

    spiral_traversal(arr);
    return 0;
}