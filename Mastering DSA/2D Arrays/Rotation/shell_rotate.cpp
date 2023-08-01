#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &arr, int offset)
{
    int n = arr.size();
    offset = offset % n; // offset must be less than n;

    // reverse the last 'offset' elements
    for (int i = n - offset, j = n - 1; i < j; i++, j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // reverse the first 'n-offset' elements
    for (int i = 0, j = n - offset - 1; i < j; i++, j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // reverse the whole array
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

vector<int> fill_one_from_shell(vector<vector<int>> &arr, int s)
{
    int minr = s - 1, minc = s - 1;
    int maxc = arr[0].size() - s;
    int maxr = arr.size() - s;
    int tot = 2 * (maxr - minr + maxc - minc);

    vector<int> oned;
    for (int i = minr, j = minc; i < maxr; i++)
        oned.push_back(arr[i][j]);

    minc++;

    for (int i = maxr, j = minc; j < maxc; j++)

        oned.push_back(arr[i][j]);

    maxr--;

    for (int i = maxr, j = maxc; i >= minr; i--)

        oned.push_back(arr[i][j]);

    maxc--;

    for (int i = minr, j = maxc; j >= minc; j--)

        oned.push_back(arr[i][j]);

    minr++;
    return oned;
}

void fill_shell_from_oned(vector<vector<int>> &arr, vector<int> &oned, int s)
{
    int minr = s - 1, minc = s - 1;
    int maxc = arr[0].size() - s;
    int maxr = arr.size() - s;
    int tot = 2 * (maxr - minr + maxc - minc);

    int idx = 0;

    for (int i = minr, j = minc; i < maxr; i++)
    {
        arr[i][j] = oned[idx];
        idx++;
    }
    minc++;

    for (int i = maxr, j = minc; j < maxc; j++)
    {

        arr[i][j] = oned[idx];
        idx++;
    }
    maxr--;

    for (int i = maxr, j = maxc; i >= minr; i--)
    {

        arr[i][j] = oned[idx];
        idx++;
    }
    maxc--;

    for (int i = minr, j = maxc; j >= minc; j--)
    {
        arr[i][j] = oned[idx];
        idx++;
    }
    minr++;
}

void rotate_shell(vector<vector<int>> &arr, int s, int r)
{
    vector<int> oned = fill_one_from_shell(arr, s);
    rotate(oned, r);
    fill_shell_from_oned(arr, oned, s);

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
        {11, 12, 13, 14, 15, 16, 17},
        {21, 22, 23, 24, 25, 26, 27},
        {31, 32, 33, 34, 35, 36, 37},
        {41, 42, 43, 44, 45, 46, 47},
        {51, 52, 53, 54, 55, 56, 57}};

    int s = 2;
    int r = 3;
    rotate_shell(arr, s, r);

    return 0;
}