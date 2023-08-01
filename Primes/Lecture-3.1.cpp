#include <bits/stdc++.h>
using namespace std;

// after caluclation o size
#define N 1000000

// SIEVE OF ERATOSTHENSES

int sieve[N + 1];
vector<int> ds;
void createSieve()
{
    for (int i = 2; i <= N; i++)
    {
        sieve[i] = 1;
    }

    for (int i = 2; i * i <= N; i++)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                if (sieve[j] != 0)
                {
                    sieve[i]++;
                    sieve[j] = 0;
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

        cout << sieve[n] << endl;
    }
    return 0;
}