// A Maze is given as N*N binary matrix of blocks where source block is the
// upper left most block i.e., maze[0][0] and destination block is lower
// rightmost block i.e., maze[N-1][N-1].
// A rat starts from source and has to reach the destination.
// The rat can move only in two directions: forward and down.

// In the maze matrix, 0 means the block is a dead end and 1 means
// the block can be used in the path from source to destination.

// Example:

// Input
// {1, 0, 0, 0}
// {1, 1, 0, 1}
// {0, 1, 0, 0}
// {1, 1, 1, 1}

// Output
// {1, 0, 0, 0}
// {1, 1, 0, 0}
// {0, 1, 0, 0}
// {0, 1, 1, 1}
// All entries in solution path are marked as 1.

// Approach

// Create a solution matrix, initially filled with 0’s.

// Create a recursive function, which takes initial matrix, output matrix
// and position of rat (i, j).

// if the position is out of the matrix or the position is not valid
// then return.

// Mark the position output[i][j] as 1 and check if the current position
// is destination or not. If destination is reached print the output
// matrix and return.

// Recursively call for position (i+1, j) and (i, j+1).
// Unmark position (i, j), i.e output[i][j] = 0.

// CODE

#include <bits/stdc++.h>
using namespace std;

#define N 4

int RatsMazeUtil(int maze[N][N], int out[N][N], int x, int y);


int isSafe(int x,int y, int maze[N][N]){
    return (x >=0 && x < N && y >=0 && y < N && maze[x][y] == 1);
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

int RatsMazeUtil(int maze[N][N], int out[N][N], int x, int y)
{
    if (x==N-1 && y==N-1 && maze[x][y] == 1){
        out[x][y] = 1;
        return 1;
    }
    
    if(isSafe(x,y,maze)){
        // if current block is part of path
        if(out[x][y]== 1) return 0;

        out[x][y]= 1;   
        if(RatsMazeUtil(maze,out,x+1, y) == 1) return 1;
        if(RatsMazeUtil(maze,out,x, y+1) == 1) return 1;

        // backtrack
        out[x][y]  =0;
        return 0;
    }
    return 0;
}

int RatsMaze()
{
    int maze[N][N] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {0, 1, 1, 1}};

    int out[N][N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            out[i][j] = 0;

    if (RatsMazeUtil(maze, out, 0, 0) == 0)
        return 0;
    else
        printSolution(out);

    return 1;
}

int main()
{
    RatsMaze();
    return 0;
}
