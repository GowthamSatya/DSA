#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int floorSqrt(long long int x)
    {
        // Your code goes here
        long long lo = 1;
        long long hi = x;

        if (x == 1)
            return 1;

        long long ans = 1;

        while (lo <= hi)
        {
            long long int mid = (lo + hi) >> 1;

            if (mid * mid == x)
                return mid;

            else if (mid * mid > x)
                hi = mid - 1;
            else
            {
                ans = mid;
                lo = mid + 1;
            }
        }

        return floor(ans);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}