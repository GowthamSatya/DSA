#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    void leftRotate(int arr[], int k, int n)
    {
        // Your code goes here

        // juggling Algorithm for left rotation

        /*
            Working

            {1,2,3,4,5,6,7} k=2;
            gcd = gcd(2,7) == 1;

            temp =1;
            j points to 1, j=0;

            while
                d=2;
                // first iteration
                swaps 1,3 -> 1,5 -> 1,7

        */

        k = k % n;
        int gcd = __gcd(k, n);
        for (int i = 0; i < gcd; i++)
        {
            int temp = arr[i];
            int j = i;
            while (1)
            {
                int d = j + k;

                if (d >= n)
                    d -= n;
                if (d == i)
                    break;

                arr[j] = arr[d];
                j = d;
            }
            arr[j] = temp;
        }
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
        int k;
        cin >> k;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            // um[a[i]]++;
        }

        Solution ob;
        ob.leftRotate(a, k, n);

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";

        cout << "\n";
    }
    return 0;
}