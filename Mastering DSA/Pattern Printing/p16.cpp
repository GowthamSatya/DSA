/*
Pattern

n=6

A
B B
C C C
D D D D
E E E E E
F F F F F F
*/

// code

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int ans = 65;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << (char)ans << " ";
        }
        ans++;
        cout << '\n';
    }

    return 0;
}