/*
Pattern

n=6

6 6 6 6 6 6 6 6 6 6 6
6 5 5 5 5 5 5 5 5 5 6
6 5 4 4 4 4 4 4 4 5 6
6 5 4 3 3 3 3 3 4 5 6
6 5 4 3 2 2 2 3 4 5 6
6 5 4 3 2 1 2 3 4 5 6
6 5 4 3 2 2 2 3 4 5 6
6 5 4 3 3 3 3 3 4 5 6
6 5 4 4 4 4 4 4 4 5 6
6 5 5 5 5 5 5 5 5 5 6
6 6 6 6 6 6 6 6 6 6 6

*/

// code

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // printing the first half
    int k = n;
    for (int i = 0; i < n; i++)
    {
        // print the space
        for (int j = 0; j < i; j++)
        {
            cout << k << " ";
            k--;
        }

        // print the row
        for (int j = 0; j < 2 * (n - i) - 1; j++)
        {
            cout << k << " ";
        }

        // print the space
        for (int j = 0; j < i; j++)
        {
            k++;
            cout << k << " ";
        }

        cout << '\n';
    }

    for (int i = n - 1; i > 0; i--)
    {
        // print the space
        for (int j = 1; j < i; j++)
        {
            cout << k << " ";
            k--;
        }

        // print the row
        for (int j = 0; j <= 2 * (n - i); j++)
        {
            cout << k << " ";
        }

        // print the space
        for (int j = 1; j < i; j++)
        {
            k++;
            cout << k << " ";
        }

        cout << '\n';
    }

    return 0;
}