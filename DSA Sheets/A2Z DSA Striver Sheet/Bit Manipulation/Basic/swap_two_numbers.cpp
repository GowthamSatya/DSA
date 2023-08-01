#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    pair<int, int> get(int a, int b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;

        return {a, b};
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;

        Solution ob;
        pair<int, int> p = ob.get(a, b);
        cout << p.first << ' ' << p.second << endl;
    }
    return 0;
}

// } Driver Code Ends