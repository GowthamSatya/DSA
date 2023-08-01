#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(int n, int k, vector<vector<int>> &res, vector<int> &temp, int idx, int sum)
    {
        if (k == 0 && sum == n)
        {
            res.push_back(temp);
            return;
        }

        if (sum > n)
            return;

        for (int i = idx; i <= 9; i++)
        {
            if (i > n)
                break;

            temp.push_back(i);
            solve(n, k - 1, res, temp, i + 1, sum + i);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(int K, int N)
    {
        // code here
        vector<vector<int>> res;
        vector<int> temp;

        solve(N, K, res, temp, 1, 0);
        return res;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans)
        {
            for (auto it : arr)
                cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}