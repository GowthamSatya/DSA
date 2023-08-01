#include <bits/stdc++.h>
using namespace std;

// after caluclation o size
#define N 1000000

// SIEVE OF ERATOSTHENSES

int sieve[N + 1];
vector<int> ds;
void createSieve()
{
    for (int i = 1; i <= N; i++)
    {
        sieve[i] = i;
    }

    for (int i = 2; i * i <= N; i++)
    {
        if (sieve[i] == i)
        {
            for (int j = i * i; j <= N; j += i)
            {
                if (sieve[j] == j)
                {
                    sieve[j] = i;
                }
            }
        }
    }
}

int main()
{
    // TC = O(N log(LogN))
    createSieve();

    int q;
    cin >> q;

    while (q--)
    {
        int n;
        cin >> n;

        while (n != 1)
        {
            cout << sieve[n] << " ";
            n /= sieve[n];
        }
        cout << '\n';
    }
    return 0;
}