// Pattern
/*
    n=6;

    Output
    * * * * * *
    * * * * * *
    * * * * * *
    * * * * * *
    * * * * * *
    * * * * * *
*/

// Code
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // outer loop for rows
    for (int i = 0; i < n; i++)
    {
        // inner loop for columns
        for (int j = 0; j < n; j++)
        {
            cout << "*"
                 << " ";
        }
        cout << endl;
    }

    return 0;
}