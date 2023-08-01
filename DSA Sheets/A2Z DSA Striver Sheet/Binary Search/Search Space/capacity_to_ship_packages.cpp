#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool helper(int arr[], int mid, int n, int d)
    {
        int sum = 0;
        int day = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum > mid)
            {
                day++;
                sum = arr[i];
            }
        }
        day++;
        return day <= d;
    }

public:
    int leastWeightCapacity(int arr[], int N, int D)
    {
        // code here
        int sum = 0;
        int maxi = -1;
        for (int i = 0; i < N; i++)
        {
            sum += arr[i];
            maxi = max(maxi, arr[i]);
        }

        int lo = maxi;
        int hi = sum;
        int ans = -1;

        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;

            if (helper(arr, mid, N, D))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, D;
        cin >> N;

        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        cin >> D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr, N, D) << endl;
    }
    return 0;
}