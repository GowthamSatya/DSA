//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define UNASSIGNED 0

#define N 9

// } Driver Code Ends
class Solution
{
    bool isValid(int grid[N][N], int c, int i, int j)
    {
        for (int k = 0; k < 9; k++)
        {
            if (grid[k][j] == c)
                return false;

            if (grid[i][k] == c)
                return false;
            if (grid[3 * (i / 3) + k / 3][3 * (j / 3) + k % 3] == c)
                return false;
        }
        return true;
    }

public:
    // Function to find a solved Sudoku.
    bool SolveSudoku(int grid[N][N])
    {
        // Your code here
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (grid[i][j] == 0)
                {
                    for (int c = 1; c <= 9; c++)
                    {
                        if (isValid(grid, c, i, j))
                        {
                            grid[i][j] = c;

                            if (SolveSudoku(grid) == true)
                                return true;
                            else
                                grid[i][j] = 0;
                        }
                    }

                    return false;
                }
            }
        }
        return true;
    }

    // Function to print grids of the Sudoku.
    void printGrid(int grid[N][N])
    {
        // Your code here
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << grid[i][j] << " ";
            }
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int grid[N][N];

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                cin >> grid[i][j];

        Solution ob;

        if (ob.SolveSudoku(grid) == true)
            ob.printGrid(grid);
        else
            cout << "No solution exists";

        cout << endl;
    }

    return 0;
}