#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void MakeZeros(vector<vector<int>> &matrix)
    {
        // Code here
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    int top = i - 1 >= 0 ? matrix[i - 1][j] : 0;
                    int left = j - 1 >= 0 ? matrix[i][j - 1] : 0;
                    int right = j + 1 < m ? matrix[i][j + 1] : 0;
                    int bottom = i + 1 < n ? matrix[i + 1][j] : 0;

                    int sum = top + left + right + bottom;

                    if (i - 1 >= 0)
                        matrix[i - 1][j] = 0;
                    if (i + 1 < n)
                        matrix[i + 1][j] = 0;
                    if (j - 1 >= 0)
                        matrix[i][j - 1] = 0;
                    if (j + 1 < m)
                        matrix[i][j + 1] = 0;
                }
            }
        }
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> matrix[i][j];
            }
        }
        Solution ob;
        ob.MakeZeros(matrix);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << matrix[i][j] << " ";
            cout << "\n";
        }
    }
    return 0;
}