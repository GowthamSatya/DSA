/*
Pattern

n=6

A
A B
A B C
A B C D
A B C D E
A B C D E F

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
        int ans = 65;
        for (int j = 0; j <= i; j++)
        {
            cout << (char)ans << " ";
            ans++;
        }
        cout << '\n';
    }

    return 0;
}