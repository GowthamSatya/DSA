//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
class Solution
{
    int get_first(int arr[], int n, int x)
    {

        int lo = 0, hi = n - 1;
        int st = -1;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            if (arr[mid] == x)
            {
                st = mid;
                hi = mid - 1;
            }
            else if (arr[mid] < x)
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        return st;
    }

    int get_last(int arr[], int n, int x)
    {
        int lo = 0, hi = n - 1;
        int end = -1;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            if (arr[mid] == x)
            {
                end = mid;
                lo = mid + 1;
            }
            else if (arr[mid] < x)
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        return end;
    }

public:
    /* if x is present in arr[] then returns the count
        of occurrences of x, otherwise returns 0. */
    int count(int arr[], int n, int x)
    {
        // code here
        int st = get_first(arr, n, x);
        int e = get_last(arr, n, x);

        if (st == -1 && e == -1)
            return 0;

        return (e - st + 1);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}