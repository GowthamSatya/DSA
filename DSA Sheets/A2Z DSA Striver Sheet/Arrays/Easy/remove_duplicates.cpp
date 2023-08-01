#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int remove_duplicate(int a[], int n)
    {
        // code here
        // Two Pointer Approach
        int i = 0;

        for (int j = 1; j < n; j++)
        {
            if (a[i] != a[j])
            {
                a[i + 1] = a[j];
                i++;
            }
        }

        return i + 1;

        //  TC -> O(n)
        //  SC -> O(1)
    }
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int a[N];
        for (int i = 0; i < N; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        int n = ob.remove_duplicate(a, N);

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}