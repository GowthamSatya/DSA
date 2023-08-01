/*
Pattern

n=6

************
*****  *****
****    ****
***      ***
**        **
*          *
*          *
**        **
***      ***
****    ****
*****  *****
************
*/

// code

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // first half of pattern
    for (int i = 0; i < n; i++)
    {
        // print the stars half;

        for (int j = 0; j <= n - i - 1; j++)
        {
            cout << "*";
        }

        // print the spaces
        for (int j = 0; j < 2 * i; j++)
        {
            cout << " ";
        }

        // print second half of stars
        for (int j = 0; j <= n - i - 1; j++)
        {
            cout << "*";
        }
        cout << '\n';
    }

    // printing the second half
    for (int i = n; i > 0; i--)
    {
        // print the stars half;
        for (int j = 0; j <= n - i; j++)
        {
            cout << "*";
        }

        // print the spaces
        for (int j = 0; j < 2 * (i - 1); j++)
        {
            cout << " ";
        }

        // print second half of stars
        for (int j = 0; j <= n - i; j++)
        {
            cout << "*";
        }
        cout << '\n';
    }

    return 0;
}