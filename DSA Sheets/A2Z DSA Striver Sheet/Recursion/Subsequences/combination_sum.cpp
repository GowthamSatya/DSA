#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void helper(vector<int> &A, int B, vector<vector<int>> &ans, vector<int> &temp, int idx)
    {
        if (idx == A.size())
        {
            if (B == 0)
                ans.push_back(temp);
            return;
        }

        // pick the element at index

        if (A[idx] <= B)
        {
            temp.push_back(A[idx]);
            helper(A, B - A[idx], ans, temp, idx);
            temp.pop_back();
        }

        // not pick remove element from temp

        helper(A, B, ans, temp, idx + 1);
    }

public:
    // Function to return a list of indexes denoting the required
    // combinations whose sum is equal to given number.
    vector<vector<int>> combinationSum(vector<int> &A, int B)
    {
        // Your code here
        sort(A.begin(), A.end());
        vector<vector<int>> ans;
        vector<int> temp;

        // sort and remove duplicates in array
        for (int i = 1; i < A.size(); i++)
        {
            if (A[i] == A[i - 1])
            {
                A.erase(A.begin() + i);
                i--;
            }
        }

        helper(A, B, ans, temp, 0);

        return ans;
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
        vector<int> A;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            A.push_back(x);
        }
        int sum;
        cin >> sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
        if (result.size() == 0)
        {
            cout << "Empty";
        }
        for (int i = 0; i < result.size(); i++)
        {
            cout << '(';
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j];
                if (j < result[i].size() - 1)
                    cout << " ";
            }
            cout << ")";
            cout << '\n';
        }
    }
}