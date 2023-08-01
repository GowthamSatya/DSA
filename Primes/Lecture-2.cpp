#include <bits/stdc++.h>
using namespace std;

#define N 1000000

// SIEVE OF ERATOSTHENSES

bool sieve[N + 1];
void createSieve()
{
    for (int i = 2; i <= N; i++)
    {
        sieve[i] = true;
    }

    for (int i = 2; i * i <= N; i++)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                sieve[j] = false;
            }
        }
    }
}

bool checkPrime(int n)
{
    int cnt = 0;

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++;
            if ((n / i) != i)
            {
                cnt++;
            }
        }
    }

    if (cnt == 2)
        return 1;
    else
        return 0;
}

int main()
{
    int t;
    cin >> t;
    createSieve();

    while (t--)
    {
        int n;
        cin >> n;

        if (sieve[n])
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
    }
}