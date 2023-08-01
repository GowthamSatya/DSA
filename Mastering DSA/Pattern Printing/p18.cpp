/*
Pattern

n=6

F
E F
D E F
C D E F
B C D E F
A B C D E F
*/

// code

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int ans = 65 + n - i;
        for (int j = 0; j < i; j++)
        {
            cout << (char)ans << " ";
            ans++;
        }
        cout << '\n';
    }

    return 0;
}