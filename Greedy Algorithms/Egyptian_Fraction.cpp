#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// ============ EGYPTIAN FRACTION =============
// ==> STATEMENT
// Every positive fraction can be represented as sum of unique unit fractions. A fraction is unit fraction if numerator is 1 and denominator is a positive integer, for example 1/3 is a unit fraction. Such a representation is called Egyptian Fraction as it was used by ancient Egyptians.

// ==> EXAMPLES
// Egyptian Fraction Representation of 2/3 is 1/2 + 1/6
// Egyptian Fraction Representation of 6/14 is 1/3 + 1/11 + 1/231
// Egyptian Fraction Representation of 12/13 is 1/2 + 1/3 + 1/12 + 1/156

// ==> APPROACH
// We can generate Egyptian Fractions using Greedy Algorithm. For a given number of the form ‘nr/dr’ where dr > nr, first find the greatest possible unit fraction, then recur for the remaining part. For example, consider 6/14, we first find ceiling of 14/6, i.e., 3. So the first unit fraction becomes 1/3, then recur for (6/14 – 1/3) i.e., 4/42.

void printEgyptianFractions(int nr, int dr)
{
    if (nr == 0 || dr == 0)
        return;
    if (dr % nr == 0)
    {
        cout << "1/" << dr / nr << endl;
        return;
    }
    int f = dr / nr + 1;
    cout << "1/ " << f << endl;
    int new_nr = (nr * f) - (dr);
    int new_dr = f * dr;
    printEgyptianFractions(new_nr, new_dr);
}

int main()
{
    int nr = 6, dr = 14;
    printEgyptianFractions(nr, dr);
    return 0;
}