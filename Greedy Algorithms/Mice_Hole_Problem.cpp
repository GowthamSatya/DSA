#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// ============= MICE HOLE PROBLEM =============
// ==> STATEMENT
// There are N Mice and N holes are placed in a straight line. Each hole can accommodate only 1 mouse. A mouse can stay at his position, move one step right from x to x + 1, or move one step left from x to x -1. Any of these moves consumes 1 minute. Assign mice to holes so that the time when the last mouse gets inside a hole is minimized.

// ==> EXAMPLES
// Input : positions of mice are:
//           4 -4 2
//         positions of holes are:
//           4 0 5
// Output :  4
// Assign mouse at position x = 4 to hole at
// position x = 4 : Time taken is 0 minutes
// Assign mouse at position x=-4 to hole at
// position x = 0 : Time taken is 4 minutes
// Assign mouse at position x=2 to hole at
// position x = 5 : Time taken is 3 minutes
// After 4 minutes all of the mice are in the holes.
// Since, there is no combination possible where
// the last mouse's time is less than 4,
// answer = 4.

// ==> APPROACH
// This problem can be solved using greedy strategy. We can put every mouse to its nearest hole to minimize the time. This can be done by sorting the positions of mice and holes. This allows us to put the ith mice to the corresponding hole in the holes list. We can then find the maximum difference between the mice and corresponding hole position.

void calcMaxTime(vector<int> m, vector<int> h)
{
    sort(m.begin(), m.end());
    sort(h.begin(), h.end());

    int max = 0;

    for (int i = 0; i < m.size(); i++)
    {
        if (max < abs(m[i] - h[i]))
            max = abs(m[i] - h[i]);
    }
    cout << max << endl;
}

int main()
{

    vector<int> mice_pos = {-10, -79, -79, 67, 93, -85, -28, -94};
    vector<int> hole_pos = {-2, 9, 69, 25, -31, 23, 50, 78};

    calcMaxTime(mice_pos, hole_pos);
    return 0;
}