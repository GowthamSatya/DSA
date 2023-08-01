#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(int arr[], int n)
    {
        // complete the function here
        int lo = 0, hi = n - 1;

        while (lo <= hi)
        {
            int m = lo + (hi - lo) / 2;

            if (lo == hi)
                return arr[lo];

            if (arr[m] <= arr[lo] && arr[m] <= arr[hi])
                lo++, hi--;
            else if (arr[m] >= arr[hi])
                lo = m + 1;
            else
                hi = m - 1;
        }

        return arr[hi];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.findMin(a, n) << endl;
    }
    return 0;
}