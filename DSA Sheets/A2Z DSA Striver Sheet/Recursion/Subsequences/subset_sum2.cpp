#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, int idx)
    {
        ans.push_back(temp);

        for (int i = idx; i < nums.size(); i++)
        {
            if (i != idx && nums[i] == nums[i - 1])
                continue;

            temp.push_back(nums[i]);
            solve(nums, ans, temp, i + 1);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> printUniqueSubsets(vector<int> &nums)
    {
        // Write your code here
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;

        solve(nums, ans, temp, 0);
        return ans;
    }
};

int main()
{
    int t = 1;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++)
        {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++)
                cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    }

    return 0;
}