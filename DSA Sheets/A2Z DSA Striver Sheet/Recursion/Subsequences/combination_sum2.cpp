#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(vector<int> &candidates, vector<vector<int>> &ans, vector<int> &temp, int target, int idx)
    {
        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }

        // pick the candidate
        for (int i = idx; i < candidates.size(); i++)
        {
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;
            if (target < candidates[i])
                break;

            temp.push_back(candidates[i]);
            solve(candidates, ans, temp, target - candidates[i], i + 1);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        // Write your code here
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> temp;

        solve(candidates, ans, temp, target, 0);

        return ans;
    }
};

int main()
{

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[";
        for (int i = 0; i < comb.size(); i++)
        {
            cout << "[";
            for (int j = 0; j < comb[i].size(); j++)
            {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << "]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}