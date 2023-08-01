#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function returns the second
    // largest elements
    int print2largest(int arr[], int n)
    {
        // code here

        // first get the max element
        int maxi = INT_MIN;
        int prev = -1;

        for (int i = 0; i < n; i++)
            maxi = max(maxi, arr[i]);

        // get the second max element
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > prev && arr[i] != maxi)
                prev = arr[i];
        }

        return prev;
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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}