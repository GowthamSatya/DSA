#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findOnce(int arr[], int n)
    {
        // code here.
        int l = 0, h = n - 1;

        while (l <= h)
        {
            int m = l + (h - l) / 2;

            if ((m % 2 == 0 && arr[m] == arr[m + 1]) || (m % 2 == 1 && arr[m] == arr[m - 1]))
                l = m + 1;
            else
                h = m - 1;
        }

        return arr[l];
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
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        Solution ob;

        int res = ob.findOnce(A, n);
        cout << res << endl;
    }

    return 0;
}