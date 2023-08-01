#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void bitManipulation(int num, int i)
    {
        // your code here

        // get ith bit;
        int get = (num & (1 << (i - 1))) ? 1 : 0;
        cout << get << " ";

        // set ith bit;
        cout << (num | (1 << (i - 1))) << " ";

        // clear ith bit
        cout << (num & ~(1 << (i - 1))) << " ";
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends