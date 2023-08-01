// Problem Statement

// Given a N*N board with the Knight placed on the first block of an empty board.
// Moving according to the rules of chess knight must visit each square exactly once.
// Print the order of each cell in which they are visited.

// Example

// Input :
// N = 8

// Output:
// 0  59  38  33  30  17   8  63
// 37  34  31  60   9  62  29  16
// 58   1  36  39  32  27  18   7
// 35  48  41  26  61  10  15  28
// 42  57   2  49  40  23   6  19
// 47  50  45  54  25  20  11  14
// 56  43  52   3  22  13  24   5
// 51  46  55  44  53   4  21  12

// Approach by Backtracking

// If all squares are visited
//     print the solution
// Else
//    a) Add one of the next moves to solution vector and recursively
//    check if this move leads to a solution. (A Knight can make maximum
//    eight moves. We choose one of the 8 moves in this step).
//    b) If the move chosen in the above step doesn't lead to a solution
//    then remove this move from the solution vector and try other
//    alternative moves.
//    c) If none of the alternatives work then return false (Returning false
//    will remove the previously added item in recursion and if false is
//    returned by the initial call of recursion then "no solution exists" )

// CODE

// C++ program for Knight Tour problem
#include <bits/stdc++.h>
using namespace std;

#define N 8

int solveKTUtil(int x, int y, int movei, int sol[N][N],
                int xMove[], int yMove[]);

int isSafe(int x, int y, int sol[N][N])
{
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

void printSolution(int sol[N][N])
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
            cout << " " << setw(2) << sol[x][y] << " ";
        cout << endl;
    }
}

int solveKT()
{
    int sol[N][N];

    /* Initialization of solution matrix */
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;

    /* xMove[] and yMove[] define next move of Knight.
    xMove[] is for next value of x coordinate
    yMove[] is for next value of y coordinate */
    int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    // Since the Knight is initially at the first block
    sol[0][0] = 0;

    /* Start from 0,0 and explore all tours using
    solveKTUtil() */
    if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0)
    {
        cout << "Solution does not exist";
        return 0;
    }
    else
        printSolution(sol);

    return 1;
}

int solveKTUtil(int x, int y, int movei, int sol[N][N],
                int xMove[8], int yMove[8])
{
    int k, next_x, next_y;
    if (movei == N * N)
        return 1;

    for (k = 0; k < 8; k++)
    {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isSafe(next_x, next_y, sol))
        {
            sol[next_x][next_y] = movei;
            if (solveKTUtil(next_x, next_y, movei + 1, sol,
                            xMove, yMove) == 1)
                return 1;
            else
                // backtracking
                sol[next_x][next_y] = -1;
        }
    }
    return 0;
}

int main()
{
    solveKT();
    return 0;
}