// <===== PROBLEM ======>

// Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence
// 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15,
//  … shows the first 11 ugly numbers.By convention, 1 is included.
//  Given a number n, the task is to find n’th Ugly number.

// <===== CODE ======>

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

unsigned getNthUglyNo(int n)
{
    int ugly[n];
    ugly[0] = 1;
    unsigned int i2 = 0, i3 = 0, i5 = 0;
    unsigned int next_multiple_of_2 = 2;
    unsigned int next_multiple_of_3 = 3;
    unsigned int next_multiple_of_5 = 5;
    unsigned int next_ugly_no = 1;

    for (int i = 1; i < n; i++)
    {
        next_ugly_no = min(next_multiple_of_2, min(next_multiple_of_3, next_multiple_of_5));
        ugly[i] = next_ugly_no;
        if (next_ugly_no == next_multiple_of_2)
        {
            i2++;
            next_multiple_of_2 = ugly[i2] * 2;
        }
        if (next_ugly_no == next_multiple_of_3)
        {
            i3++;
            next_multiple_of_3 = ugly[i3] * 3;
        }
        if (next_ugly_no == next_multiple_of_5)
        {
            i5++;
            next_multiple_of_5 = ugly[i5] * 5;
        }
    }

    return next_ugly_no;
}

int main()
{
    int n;
    string ch;
    cout << "Enter Number : ";
    cin >> n;
    if (n == 1)
        ch = "st";
    else if (n == 2)
        ch = "nd";
    else if (n == 3)
        ch = "rd";
    else
        ch = "th";
    cout << n << ch << " Ugly Number : " << getNthUglyNo(n);
}

// Time Complexity : O(n)
// Space Complexity : O(n)