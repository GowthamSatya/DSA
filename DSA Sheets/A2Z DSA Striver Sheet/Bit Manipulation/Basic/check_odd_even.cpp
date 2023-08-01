#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string oddEven(int N)
    {
        // code here
        return (N & 1) ? "odd" : "even";
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.oddEven(N) << endl;
    }
    return 0;
}