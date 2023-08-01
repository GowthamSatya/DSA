#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool arraySortedOrNot(int arr[], int n)
    {
        // code here
        // we are linearly traversing the array
        for (int i = 1; i < n; i++)
        {
            // if any element i is less than its previous element
            // then return false
            if (arr[i] < arr[i - 1])
                return false;
        }
        return true;
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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        bool ans = ob.arraySortedOrNot(arr, n);
        cout << ans << "\n";
    }
    return 0;
}