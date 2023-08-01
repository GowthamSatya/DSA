#include <bits/stdc++.h>

using namespace std;
#define ll long long

class Solution
{
    ll findNcR(int n, int r)
    {
        int res = 1;
        for (int i = 0; i < r; i++)
        {
            res = res * (n - i);
            res = res / (i + 1);
        }

        return res;
    }

public:
    vector<ll> nthRowOfPascalTriangle(int n)
    {
        // code here
        vector<ll> res;
        res.push_back(1);
        int ans = 1;
        for (int i = 1; i < n; i++)
        {
            ans = ans * (n - i);
            ans = ans / i;
            res.push_back(ans);
        }

        return res;
    }
};

void printAns(vector<ll> &ans)
{
    for (auto &x : ans)
    {
        cout << x << " ";
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}