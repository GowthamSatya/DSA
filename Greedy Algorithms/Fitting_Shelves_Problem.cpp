#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// ============== FITTING SHELVES PROBLEM =============
// => STATEMENT
// Given length of wall w and shelves of two lengths m and n, find the number of each type of shelf to be used and the remaining empty space in the optimal solution so that the empty space is minimum. The larger of the two shelves is cheaper so it is preferred. However cost is secondary and first priority is to minimize empty space on wall.

// => EXAMPLE
// Input : w = 24 m = 3 n = 5
// Output : 3 3 0
// We use three units of both shelves
// and 0 space is left.
// 3 * 3 + 3 * 5 = 24
// So empty space  = 24 - 24 = 0
// Another solution could have been 8 0 0
// but since the larger shelf of length 5
// is cheaper the former will be the answer.

// => APPROACH
// A simple and efficient approach will be to try all possible combinations of shelves that fit within the length of the wall.
// To implement this approach along with the constraint that larger shelf costs less than the smaller one, starting from 0, we increase no of larger type shelves till they can be fit. For each case we calculate the empty space and finally store that value which minimizes the empty space. if empty space is same in two cases we prefer the one with more no of larger shelves.

void minSpacePreferLarge(int w, int m, int n)
{
    int m_count = 0, n_count = 0;
    int min_space = w;

    int p = w / m, q = 0;
    int rem = w % m;
    m_count = p;
    n_count = q;
    min_space = rem;

    while (w >= n)
    {
        q++;
        w -= n;
        p = w / m;
        rem = w % m;

        if (rem <= min_space)
        {
            m_count = p;
            n_count = q;
            min_space = rem;
        }
    }

    cout << m_count << " " << n_count << " " << min_space << endl;
}

int main()
{
    int wall = 29, m = 3, n = 9;
    minSpacePreferLarge(wall, m, n);

    wall = 76, m = 1, n = 10;
    minSpacePreferLarge(wall, m, n);
    return 0;
}