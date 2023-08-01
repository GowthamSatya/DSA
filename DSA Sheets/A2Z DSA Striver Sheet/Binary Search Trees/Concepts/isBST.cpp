#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isBSTTraversal(vector<int> &nums)
    {
        // your code here
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] >= nums[i])
                return false;
        }

        return true;
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
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            nums[i] = k;
        }

        Solution ob;
        bool res = ob.isBSTTraversal(nums);
        if (res)
            cout << "True";
        else
            cout << "False";

        cout << "\n";
    }
    return 0;
}
