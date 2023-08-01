#include <bits/stdc++.h>
using namespace std;

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

vector<int> find(int arr[], int n, int x)
{
    // code here
    int st = get_first(arr, n, x);
    int e = get_last(arr, n, x);

    return {st, e};
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n], i;
        for (i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> ans;
        ans = find(arr, n, x);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}