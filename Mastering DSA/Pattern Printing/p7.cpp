/*
Pattern

n=6

         *
        ***
       *****
      *******
     *********
    ***********
*/

// code

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // outer loop - n rows
    for (int i = 0; i < n; i++)
    {
        // printing the spaces
        for (int j = 0; j < n - i; j++)
            cout << " ";

        // printing the stars
        for (int j = 0; j < 2 * i + 1; j++)
            cout << "*";
        cout << '\n';
    }

    return 0;
}