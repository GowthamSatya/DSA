#include <bits/stdc++.h>
using namespace std;

// Basics of Primes

// n = a*b*c find a,b,c
// a!=b!=c and a,b,c != 1
// if possible print yes
int main()
{
    int n;
    cin >> n;

    int a = 1, b = 1, c = 1;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            a = i;
            break;
        }
    }

    n = n / a;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i != a)
            {
                b = min(b, i);
            }

            if ((n / i) != i)
            {
                if ((n / i) != a)
                {
                    b = min(b, n / i);
                }
            }
        }
    }

    c = n / b;

    if (a != b && b != c && c != 1)
        cout << "yes";
    else
        cout << "no";

    return 0;
}