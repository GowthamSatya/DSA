#include <iostream>
using namespace std;

// Efficient Way to find nCr (O(r) time and O(1) space)`)
// long long int nCr(int n, int r)
// {
//     long long int ans = 1;
//     if (r > n - r)
//         r = n - r;

//     for (int i = 0; i < r; i++)
//     {
//         ans *= (n - i);
//         ans /= (i + 1);
//     }
//     return ans;
// }

unsigned long long int catalanNumber(unsigned int n)
{
    unsigned long long int catalan[n + 1];
    catalan[0] = 1;
    catalan[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        catalan[i] = 0;
        for (int j = 0; j < i; j++)
        {
            catalan[i] += catalan[j] * catalan[i - j - 1];
        }
    }

    return catalan[n];
}

int main()
{
    unsigned int n;
    cout
        << "Enter A Number : ";
    cin >> n;

    cout << "The " << n << "th Catalan Number is : " << catalanNumber(n);
}