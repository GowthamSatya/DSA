#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(int A[], int N)
    {
        int x = 0;

        for (int i = 0; i < N; i++)
        {
            x ^= A[i];
        }

        return x;
    }
};

int main()
{
    int t, len;
    cin >> t;
    while (t--)
    {
        cin >> len;
        int arr[len];
        for (int i = 0; i < len; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.search(arr, len) << '\n';
    }
    return 0;
}
