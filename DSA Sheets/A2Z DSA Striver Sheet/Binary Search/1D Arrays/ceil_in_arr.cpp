//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

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
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends

pair<int, int> getFloorAndCeil(int arr[], int n, int x)
{
    // code here
    sort(arr, arr + n);

    int lo = 0, hi = n - 1;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (arr[mid] == x)
            return {arr[mid], arr[mid]};
        else if (arr[mid] < x)
            lo = mid + 1;
        else
            hi = mid - 1;
    }

    if (lo > n - 1)
        return {arr[hi], -1};
    else if (hi < 0)
        return {-1, arr[lo]};
    return {arr[hi], arr[lo]};
}