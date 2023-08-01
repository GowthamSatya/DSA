#include <bits/stdc++.h>
using namespace std;

#define N 1000000

bool sieve[N + 1];
// Segemented Sieve

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
            for (int j = i * i; j <= N; j++)
            {
                sieve[j] = 0;
            }
        }
    }
}

vector<int> generatePrimes(int n)
{
    vector<int> ans;

    for (int i = 2; i <= n; i++)
    {
        if (sieve[i])
        {
            ans.push_back(i);
        }
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;
    createSieve();

    while (t--)
    {
        int l, r;
        cin >> l >> r;

        // generate all primes till sqrt(r);
        vector<int> primes = generatePrimes(sqrt(r));

        // create dummy array of size r-l+1 and make everyone as 1
        int dummy[r - l + 1];
        for (int i = 0; i < r - l + 1; i++)
            dummy[i] = 1;

        for (auto pr : primes)
        {
            int first = (l / pr) * pr;

            if (first < l)
                first += pr;

            // for all primes mark its multiples as false
            for (int j = max(first, pr * pr); j <= r; j += pr)
            {
                dummy[j - l] = 0;
            }
        }

        // get all primes
        for (int i = l; i <= r; i++)
        {
            if (dummy[i - l])
            {
                cout << i << " ";
            }
        }

        cout << '\n';
    }

    return 0;
}