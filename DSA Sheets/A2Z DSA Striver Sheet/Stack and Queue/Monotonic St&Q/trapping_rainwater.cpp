#include <bits/stdc++.h>
using namespace std;

class Solution
{

    // Function to find the trapped water between the blocks.
public:
    long long trappingWater(int arr[], int n)
    {
        // code here
        long long res = 0;

        int l = 0, r = n - 1;
        int l_max = 0, r_max = 0;
        while (l <= r)
        {
            if (arr[l] <= arr[r])
            {
                if (arr[l] > l_max)
                    l_max = arr[l];
                else
                    res += (l_max - arr[l]);

                l++;
            }
            else
            {
                if (arr[r] >= r_max)
                    r_max = arr[r];
                else
                    res += (r_max - arr[r]);

                r--;
            }
        }

        return res;
    }
};

int main()
{

    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;

        // size of array
        cin >> n;

        int a[n];

        // adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        // calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
}