#include <bits/stdc++.h>
using namespace std;

#define LEN 2 * 100000

class Solution
{
public:
    int sv[LEN + 1];
    void sieve()
    {
        for (int i = 1; i <= LEN; i++)
            sv[i] = i;

        for (int i = 2; i * i <= LEN; i++)
        {
            if (sv[i] == i)
            {
                for (int j = i * i; j <= LEN; j += i)
                {
                    if (sv[j] == j)
                        sv[j] = i;
                }
            }
        }
    }

    vector<int> findPrimeFactors(int N)
    {

        // Write your code here
        vector<int> ans;

        while (N > 1)
        {
            ans.push_back(sv[N]);
            N = N / sv[N];
        }

        return ans;
    }
};

int main()
{
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--)
    {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}