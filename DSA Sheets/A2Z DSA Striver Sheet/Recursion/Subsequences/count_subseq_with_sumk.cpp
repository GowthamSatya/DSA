#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int idx, int arr[], int n, int sum)
    {
        if (sum == 0)
            return 1;

        if (sum < 0)
            return 0;

        if (idx >= n)
            return 0;

        int pick = solve(idx + 1, arr, n, sum - arr[idx]);
        int notPick = solve(idx + 1, arr, n, sum);

        return pick + notPick;
    }

public:
    int perfectSum(int arr[], int n, int sum)
    {
        // Your code goes here
        sort(arr, arr + n);
        int ans = solve(0, arr, n, sum);
        return ans;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.perfectSum(a, n, sum) << "\n";
    }
    return 0;
}