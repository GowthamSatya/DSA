#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // arr: input array
    // n: size of array
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n)
    {
        // Your code
        // kadanes algo for max subarray sum
        long long sum = 0, maxi = INT_MIN;
        int start = -1, ansSt = -1, ansEnd = -1;
        for (int i = 0; i < n; i++)
        {
            // to print the subarray
            // if (sum == 0)
            //     start = i;
            sum += arr[i];

            if (sum > maxi)
            {
                maxi = sum;
                // ansSt = start, ansEnd = i;
            }
            if (sum < 0)
                sum = 0;
        }

        return maxi;
    }
};

int main()
{
    int t, n;

    cin >> t;   // input testcases
    while (t--) // while testcases exist
    {

        cin >> n; // input size of array

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i]; // inputting elements of array

        Solution ob;

        cout << ob.maxSubarraySum(a, n) << endl;
    }
}