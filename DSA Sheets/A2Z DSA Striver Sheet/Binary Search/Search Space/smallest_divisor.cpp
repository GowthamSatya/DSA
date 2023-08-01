#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int helper(vector<int> &nums, int mid)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = ceil((double)nums[i] / (double)mid);
            sum += temp;
        }

        return sum;
    }

public:
    int smallestDivisor(vector<int> &nums, int K)
    {

        // Write your code here.
        int maxi = -1;
        for (auto i : nums)
        {
            maxi = max(maxi, i);
        }

        int lo = 1;
        int hi = maxi;
        int ans = -1;

        while (lo <= hi)
        {
            int mid = (lo + hi) >> 1;

            if (helper(nums, mid) <= K)
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return lo;
    }
};

int main()
{
    int t = 1;
    cin >> t;

    while (t--)
    {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++)
            cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
    }

    return 0;
}