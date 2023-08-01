#include <bits/stdc++.h>
using namespace std;

/*
A magic square of order n is an arrangement of n2 numbers,
usually distinct integers, in a square, such that the n
numbers in all rows, all columns, and both diagonals sum
to the same constant. A magic square contains the integers
from 1 to n2.
*/

// TIME COMPLEXITY : O(n^2)
// SPACE COMPLEXITY : O(n^2)

int main()
{
    int n;
    cin >> n;
    int mat[n][n];

    memset(mat, 0, sizeof(mat));

    int i = n / 2;
    int j = n - 1;

    for (int num = 1; num <= n * n;)
    {
        if (i == -1 && j == n)
        {
            j = n - 2;
            i = 0;
        }
        else
        {
            if (j == n)
                j = 0;
            if (i < 0)
                i = n - 1;
        }

        if (mat[i][j])
        {
            j -= 2;
            i++;
            continue;
        }
        else
            mat[i][j] = num++;

        j++;
        i--;
    }

    cout << "The Magic Square for n=" << n
         << "\nSum of "
            "each row or column : "
         << n * (n * n + 1) / 2 << endl;

    cout << endl
         << "Magic Matrix is : " << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cout << setw(4) << mat[i][j] << " ";
        cout << endl;
    }
}