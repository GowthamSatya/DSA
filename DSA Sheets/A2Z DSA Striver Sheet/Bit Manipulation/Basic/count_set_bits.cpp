#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int getLargestPower(int n)
    {
        int x = 0;

        while ((1 << x) <= n)
        {
            x++;
        }

        return x - 1;
    }

public:
    // n: input to count the number of set bits
    // Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        if (n == 0)
            return 0;
        // Your logic here
        int x = getLargestPower(n);

        int upto2x = x * (1 << (x - 1));
        int msb = n - (1 << x) + 1;

        int ans = upto2x + msb + countSetBits(n - (1 << x));

        return ans;
    }
};

int main()
{
    int t;
    cin >> t;   // input testcases
    while (t--) // while testcases exist
    {
        int n;
        cin >> n; // input n
        Solution ob;
        cout << ob.countSetBits(n) << endl; // print the answer
    }
    return 0;
}