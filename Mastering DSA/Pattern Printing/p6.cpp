/*
Pattern

n=6

1 2 3 4 5 6
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1
*/

// code

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = n; i > 0; i--)
    {
        for (int j = i; j > 0; j--)
        {
            cout << i - j + 1 << " ";
        }
        cout << '\n';
    }

    return 0;
}