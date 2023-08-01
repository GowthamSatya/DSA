#include <bits/stdc++.h>
using namespace std;
#define NR 10000

class Solution
{

    bool sieve[NR + 1];
    void createSieve()
    {
        for (int i = 2; i <= NR; i++)
        {
            sieve[i] = 1;
        }

        for (int i = 2; i <= NR; i++)
        {
            if (sieve[i])
            {
                for (int j = i * i; j <= NR; j += i)
                {
                    sieve[j] = 0;
                }
            }
        }
    }

public:
    vector<int> sieveOfEratosthenes(int n)
    {
        // Write Your Code here
        vector<int> ans;
        createSieve();
        for (int i = 2; i <= n; i++)
        {
            if (sieve[i])
                ans.push_back(i);
        }

        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        vector<int> primes = ob.sieveOfEratosthenes(N);
        for (auto prime : primes)
        {
            cout << prime << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends