/*
Given a number n, find the last non-zero digit in n!.
*/

#include <iostream>
#include <math.h>
using namespace std;

int d[10] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8}; // Non Zero digits of n! (n < 10)

int lastNonZeroDigit(int n)
{
    if (n < 10)
        return d[n];

    if (!(n / 10) % 2)
        return (6 * lastNonZeroDigit(n / 5) * d[n % 10]) % 10;
    else
        return (4 * lastNonZeroDigit(n / 5) * d[n % 10]) % 10;
}

int main()
{
    cout << lastNonZeroDigit(27) << endl;
    return 0;
}