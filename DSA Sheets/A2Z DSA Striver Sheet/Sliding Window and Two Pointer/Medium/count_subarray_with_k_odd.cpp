#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubarray(int n, vector<int> &nums, int k)
    {
        // Code here
        unordered_map<int, int> mp;
        int i = 0, j = 0;
        int cnt = 0;
        int cntOdd = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] & 1)
                cntOdd++;

            if (cntOdd == k)
                cnt++;

            if (mp.find(cntOdd - k) != mp.end())
                cnt += mp[cntOdd - k];

            mp[cntOdd]++;
        }

        return cnt;
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
        vector<int> nums;
        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}