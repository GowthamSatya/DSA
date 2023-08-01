#include <bits/stdc++.h>
using namespace std;

// after caluclation o size
#define N 86028121

// SIEVE OF ERATOSTHENSES

bool sieve[N + 1];
vector<int> ds;
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

    // to get the last (limit)th prime number
    // we compute the size of the array

    // int limit = 5 * 1000000;
    // int cnt = 0;
    // int size = 1;

    // for (int i = 2;; i++)
    // {
    //     if (sieve[i])
    //     {
    //         cnt++;
    //     }

    //     if (cnt == limit)
    //     {
    //         size = i;
    //         break;
    //     }
    // }

    // cout << size << endl;

    for (int i = 2; i <= N; i++)
    {
        if (sieve[i])
            ds.push_back(i);
    }
}

int main()
{
    createSieve();

    int q;
    cin >> q;

    while (q--)
    {
        int k;
        cin >> k;

        cout << ds[k - 1] << endl;
    }
    return 0;
}