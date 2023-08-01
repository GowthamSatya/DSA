#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool isPossible(vector<int> &nums, int mid, int k)
    {
        int count = 1;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (sum + nums[i] > mid)
            {
                sum = nums[i];
                count++;
            }
            else
                sum += nums[i];
        }

        return count <= k;
    }

public:
    int splitArray(vector<int> &nums, int k)
    {
        if (k > nums.size())
            return -1;
        int maxi = -1;
        int sum = 0;
        for (auto i : nums)
        {
            maxi = max(maxi, i);
            sum += i;
        }

        int lo = maxi;
        int hi = sum;
        int ans = -1;

        while (lo <= hi)
        {
            int mid = (lo + hi) >> 1;

            if (isPossible(nums, mid, k))
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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution s;
        int ans = s.splitArray(arr, k);

        cout << ans << endl;
    }

    return 0;
}