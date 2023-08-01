/*
Pattern

n=6

*          *
**        **
***      ***
****    ****
*****  *****
************
*****  *****
****    ****
***      ***
**        **
*          *

*/

// code

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        // print the numbers on left side
        for (int j = 0; j <= i; j++)
        {
            cout << '*';
        }

        // print the spaces
        for (int j = 0; j < 2 * (n - i - 1); j++)
        {
            cout << " ";
        }

        // print the num
        for (int j = 0; j <= i; j++)
        {
            cout << '*';
        }
        cout << '\n';
    }

    // print the second half
    for (int i = n - 1; i > 0; i--)
    {
        // print the numbers on left side
        for (int j = 0; j < i; j++)
        {
            cout << '*';
        }

        // print the spaces
        for (int j = 0; j < 2 * (n - i); j++)
        {
            cout << " ";
        }

        // print the num
        for (int j = 0; j < i; j++)
        {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}