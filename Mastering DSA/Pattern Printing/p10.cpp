/*
Pattern

n=6

     *
     **
     ***
     ****
     *****
     ******
     *****
     ****
     ***
     **
     *
*/

// code

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // first half of the pattern
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << '*';
        }
        cout << endl;
    }

    // second half of the pattern
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}