#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int printMaxSubSquare(int n, bool **M)
{
    int i, j;
    int **S = new int *[n];
    for (int i = 0; i < n; i++)
        S[i] = new int[n];
    int max_of_s, max_i, max_j;

    for (i = 0; i < n; i++)
        S[i][0] = M[i][0];

    for (j = 0; j < n; j++)
        S[0][j] = M[0][j];

    for (i = 1; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            if (M[i][j] == 1)
                S[i][j] = min({S[i][j - 1], S[i - 1][j],
                               S[i - 1][j - 1]}) +
                          1;
            else
                S[i][j] = 0;
        }
    }

    max_of_s = S[0][0];
    max_i = 0;
    max_j = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (max_of_s < S[i][j])
            {
                max_of_s = S[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }
    return max_of_s;
}

int main()
{

    int n;
    cin >> n;
    bool **arr = new bool *[n]
    { 0 };
    for (int i = 0; i < n; i++)
    {
        arr[i] = new bool[n]{0};
    }

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int j = a; j <= b; j++)
        {
            arr[i][j] = 1;
        }
    }
    cout << printMaxSubSquare(n, arr) << endl;
    return 0;
}
