#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sort012(int a[], int n)
    {
        // code here
        // Dutch National Flag Algorithm

        /*
            Working

            {0,1,1,1,2,,1,0,1,2,0,1}
            ^^                    ^
            lo,mid                hi

            hypothetically assume
            0...low-1 sorted 0's
            low....mid-1 sorted 1's
            hi+1...n-1 sorted 2's

            unsorted part is mid...hi
            swap the respective value to the respective boundaries

            if(arr[mid] == 0) swap(arr[lo],arr[mid]) as it belongs below low then lo++, mid++;
            if(arr[mid] == 1) mid++ no change is required
            if(arr[mid] == 2) swap(arr[hi],arr[mid]) as it belongs above hi thrn hi-- mid++;
        */

        int lo = 0, mid = 0, hi = n - 1;

        while (mid <= hi)
        {
            if (a[mid] == 0)
            {
                swap(a[lo], a[mid]);
                lo++, mid++;
            }
            if (a[mid] == 1)
                mid++;
            if (a[mid] == 2)
            {
                swap(a[hi], a[mid]);
                hi--, mid++;
            }
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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}