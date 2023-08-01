#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int> &array1, vector<int> &array2);

class Solution
{
public:
    double MedianOfArrays(vector<int> &arr1, vector<int> &arr2)
    {
        // Your code goes here
        if (arr2.size() < arr1.size())
            return MedianOfArrays(arr2, arr1);

        int n1 = arr1.size();
        int n2 = arr2.size();

        int lo = 0;
        int hi = n1;

        while (lo <= hi)
        {
            int c1 = (lo + hi) >> 1;
            int c2 = (n1 + n2 + 1) / 2 - c1;

            int l1 = c1 == 0 ? INT_MIN : arr1[c1 - 1];
            int l2 = c2 == 0 ? INT_MIN : arr2[c2 - 1];

            int r1 = c1 == n1 ? INT_MAX : arr1[c1];
            int r2 = c2 == n2 ? INT_MAX : arr2[c2];

            if (l1 <= r2 && l2 <= r1)
            {
                if ((n1 + n2) % 2 != 0)
                {
                    return max(l1, l2);
                }
                else
                {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
            }
            else if (l1 > r2)
                hi = c1 - 1;
            else
                lo = c1 + 1;
        }

        return 0.0;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> array1[i];
        }
        cin >> n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> array2[i];
        }
        Solution ob;
        cout << ob.MedianOfArrays(array1, array2) << endl;
    }
    return 0;
}