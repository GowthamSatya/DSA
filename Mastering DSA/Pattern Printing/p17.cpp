/*
Pattern

n=6

     A
    ABA
   ABCBA
  ABCDCBA
 ABCDEDCBA
ABCDEFEDCBA

*/

// code

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int k = 65;
    for (int i = 0; i < n; i++)
    {
        // print the spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        // print char first half
        for (int j = 0; j <= i; j++)
        {
            cout << (char)k;
            k++;
        }

        k -= 1;
        // print the second half
        for (int j = 0; j < i; j++)
        {
            k--;
            cout << (char)k;
        }
        cout << '\n';
    }

    return 0;
}