#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> Solve(int n, vector<int> &nums)
    {
        // Code here
        int c1 = 0, c2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            if (c1 == 0 && el2 != nums[i])
            {
                c1 = 1;
                el1 = nums[i];
            }
            else if (c2 == 0 && el1 != nums[i])
            {
                c2 = 1;
                el2 = nums[i];
            }
            else if (el1 == nums[i])
                c1++;
            else if (el2 == nums[i])
                c2++;
            else
            {
                c1--, c2--;
            }
        }

        vector<int> ls;
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (el1 == nums[i])
                cnt1++;
            if (el2 == nums[i])
                cnt2++;
        }

        if (cnt1 > floor(n / 3))
            ls.push_back(el1);
        if (cnt2 > floor(n / 3))
            ls.push_back(el2);

        if (ls.empty())
            return {-1};

        return ls;
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
        vector<int> a;
        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        Solution obj;

        vector<int> res = obj.Solve(n, a);

        for (auto x : res)
            cout << x << " ";

        cout << "\n";
    }
    return 0;
}