#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)
    {
        // code here
        int res1 = 0;
        int res2 = 0;
        int _xor = 0;

        for (int i = 0; i < N; ++i)
            _xor ^= Arr[i];

        // find the right most set bit
        _xor = (_xor & (~(_xor - 1)));

        for (int i = 0; i < N; ++i)
        {
            if (Arr[i] & _xor)
                res1 ^= Arr[i];
            else
                res2 ^= Arr[i];
        }
        if (res2 > res1)
            return {res2, res1};
        return {res1, res2};
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int N;
        cin >> N;
        long long int Arr[N];
        for (long int i = 0; i < N; i++)
            cin >> Arr[i];
        Solution ob;
        vector<long long int> ans = ob.twoOddNum(Arr, N);
        for (long long int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends