#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(vector<int> &arr, int N, int K, int i, int Xor,
              vector<vector<int>> &dp)
    {
        if (i >= N)
        {
            if (Xor == K)
                return 1;
            else
                return 0;
        }
        if (dp[i][Xor] != -1)
            return dp[i][Xor];

        int x1 = solve(arr, N, K, i + 1, Xor ^ arr[i], dp);
        int x2 = solve(arr, N, K, i + 1, Xor, dp);

        return dp[i][Xor] = x1 + x2;
    }

public:
    int subsetXOR(vector<int> arr, int N, int K)
    {
        // code here
        vector<vector<int>> dp(1001, vector<int>(1001, -1));
        return solve(arr, N, K, 0, 0, dp);
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
        int K;
        cin >> K;
        vector<int> v;
        for (int i = 0; i < N; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        Solution ob;
        cout << ob.subsetXOR(v, N, K) << endl;
    }
    return 0;
}