/*
Pattern

n=5

*
* *
* * *
* * * *
* * * * *
* * * * * *

*/

// Code

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    cout << '\n';
    for (int i = 0; i < n; i++)
    {
        // pattern change with each row
        for (int j = 0; j <= i; j++)
            cout << "*"
                 << " ";
        cout << '\n';
    }

    return 0;
}