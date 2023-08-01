#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long count(int n)
    {
        // your code here
        return 1ll * pow(2, (n * (n - 1) / 2));
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.count(n) << "\n";
    }

    return 0;
}