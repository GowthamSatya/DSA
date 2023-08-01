#include <bits/stdc++.h>
using namespace std;

bool isSafe(int r, int c, vector<string> &board, int n)
{
    int dup_r = r;
    int dup_c = c;

    // checking the top diagonal to left
    while (r >= 0 && c >= 0)
        if (board[r--][c--] == 'Q')
            return false;

    c = dup_c;
    r = dup_r;

    // checking horizontally to the left
    while (c >= 0)
        if (board[r][c--] == 'Q')
            return false;

    r = dup_r;
    c = dup_c;

    // checking bottom diagonal to the left
    while (r <= n - 1 && c >= 0)
        if (board[r++][c--] == 'Q')
            return false;

    return true;
}

void solve_hash(vector<string> &board, int col, vector<vector<string>> &ans, int n, vector<int> &left_row, vector<int> &top_diag, vector<int> &bottom_diag)
{
    // base case check
    if (col == n)
    {
        // possible positions
        ans.push_back(board);
        return;
    };

    // check every row (O(n) isSafe Approach)
    for (int row = 0; row < n; row++)
    {
        if (left_row[row] == 0 && bottom_diag[row + col] == 0 && top_diag[(n - 1) + (col - row)] == 0)
        {
            // place the queen at that position
            board[row][col] = 'Q';
            left_row[row] = 1;
            bottom_diag[row + col] = 1;
            top_diag[n - 1 + col - row] = 1;
            // recursively cheking for the next columns
            solve_hash(board, col + 1, ans, n, left_row, top_diag, bottom_diag);
            // backtracking
            board[row][col] = '.';
            left_row[row] = 0;
            bottom_diag[row + col] = 0;
            top_diag[n - 1 + col - row] = 0;
        }
    }
}

void solve(vector<string> &board, int col, vector<vector<string>> &ans, int n)
{
    // base case check
    if (col == n)
    {
        // possible positions
        ans.push_back(board);
        return;
    };

    // check every row (O(n) isSafe Approach)
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            // place the queen at that position
            board[row][col] = 'Q';
            // recursively cheking for the next columns
            solve(board, col + 1, ans, n);
            // backtracking
            board[row][col] = '.';
        }
    }
}

void solve_n_queens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);

    string s(n, '.');
    for (int i = 0; i < n; i++)
        board[i] = s;

    vector<int> left_row(n, 0), top_diag(2 * n - 1, 0), bottom_diag(2 * n - 1, 0);
    // solve(board, 0, ans, n);

    solve_hash(board, 0, ans, n, left_row, top_diag, bottom_diag);

    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << endl;
        cout << endl;
    }
}

int main()
{
    solve_n_queens(4);
    return 0;
}