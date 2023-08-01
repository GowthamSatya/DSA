#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m)
    {
        // code here
        int flip = 0, ans = 0;
        int i = 0; // pointer to move forward
        int j = 0; // pointer of unflip the flipped elemts

        while (i < n)
        {
            // counting the number of zeros
            if (arr[i] == 0)
                flip++;

            // moving the window
            while (flip > m)
            {
                // unflip the prev flipped element
                if (arr[j] == 0)
                    flip--;
                j++;
            }

            ans = max(ans, i - j + 1);
            i++;
        }

        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}