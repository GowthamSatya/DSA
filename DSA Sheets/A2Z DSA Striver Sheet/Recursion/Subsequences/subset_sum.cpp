#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(vector<int> &arr, vector<int> &ans, int N, int idx, int sum)
    {
        if (idx == N)
        {
            ans.push_back(sum);
            return;
        }

        // pick the element;
        sum += arr[idx];
        solve(arr, ans, N, idx + 1, sum);

        sum -= arr[idx];
        solve(arr, ans, N, idx + 1, sum);
    }

public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        solve(arr, ans, N, 0, 0);
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans)
        {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}