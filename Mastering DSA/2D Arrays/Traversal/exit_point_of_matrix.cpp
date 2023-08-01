#include <bits/stdc++.h>
using namespace std;

void exit_point(vector<vector<int>> &arr)
{
    int dir = 0; // var to keep direction of vector
    // 0 -east , 1- south, 2-west, 3-north

    int i = 0, j = 0;

    while (true)
    {
        // change direction if arr[i][j] == 1
        dir = (dir + arr[i][j]) % 4;
        if (dir == 0)
            j++;
        else if (dir == 1)
            i++;
        else if (dir == 2)
            j--;
        else
            i--;

        // checking boundary condition
        if (i < 0)
        {
            i++;
            break;
        }
        else if (j < 0)
        {
            j++;
            break;
        }

        else if (i == arr.size())
        {
            i--;
            break;
        }
        else if (j == arr[0].size())
        {
            j--;
            break;
        }
    }

    cout << i << " " << j << endl;
}

int main()
{
    vector<vector<int>> arr = {
        {0, 0, 1, 0},
        {1, 0, 0, 1},
        {0, 0, 0, 1},
        {1, 0, 1, 0}};

    exit_point(arr);
    return 0;
}