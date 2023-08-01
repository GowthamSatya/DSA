/*
Pattern

n=6

1          1
12        21
12       321
1234    4321
12345  54321
123456654321

*/

// code

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        // print the numbers on left side
        for (int j = 0; j <= i; j++)
        {
            k++;
            cout << k;
        }

        // print the spaces
        for (int j = 0; j < 2 * (n - i - 1); j++)
        {
            cout << " ";
        }

        // print the num
        for (int j = 0; j <= i; j++)
        {
            cout << k;
            k--;
        }
        cout << '\n';
    }

    return 0;
}