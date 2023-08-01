#include <bits/stdc++.h>
using namespace std;

class Solution
{

    void solve(int col, vector<vector<int>> &ans, vector<int> &temp, vector<int> &leftRow,
               vector<int> &upperDiag, vector<int> &lowerDiag, int n)
    {
        if (col == n)
        {
            ans.push_back(temp);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (leftRow[row] == 0 && lowerDiag[row + col] == 0 && upperDiag[n - 1 + col - row] == 0)
            {
                temp.push_back(row + 1);
                leftRow[row] = 1;
                lowerDiag[row + col] = 1;
                upperDiag[n - 1 + col - row] = 1;
                solve(col + 1, ans, temp, leftRow, upperDiag, lowerDiag, n);
                temp.pop_back();
                leftRow[row] = 0;
                lowerDiag[row + col] = 0;
                upperDiag[n - 1 + col - row] = 0;
            }
        }
    }

public:
    vector<vector<int>> nQueen(int n)
    {
        // code here
        vector<vector<int>> temp;
        vector<int> t;

        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        solve(0, temp, t, leftRow, upperDiagonal, lowerDiagonal, n);

        return temp;
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

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }
    }
    return 0;
}