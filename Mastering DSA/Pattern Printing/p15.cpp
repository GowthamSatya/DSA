/*
Pattern

n=6

A B C D E F
A B C D E
A B C D
A B C
A B
A

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
        int ans = 65;
        for (int j = 0; j < i; j++)
        {
            cout << (char)ans << " ";
            ans++;
        }
        cout << '\n';
    }

    return 0;
}