#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int N = 4;

int findCelebrity(int arr[N][N])
{
    int c = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[c][i] == 1)
        {
            c = i;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (i != c and (arr[c][i] == 1 or arr[i][c] == 0))
        {
            return -1;
        }
    }
    return c;
}

int main()
{
    int M[N][N] = {{0, 0, 1, 0},
                   {0, 0, 1, 0},
                   {0, 0, 0, 0},
                   {0, 0, 1, 0}};

    int cIdx = findCelebrity(M);
    if (cIdx > 0)
        cout << "Celebrity is " << cIdx << endl;
}

// Time Complexity : O(n)
// Space Complexity : O(1)