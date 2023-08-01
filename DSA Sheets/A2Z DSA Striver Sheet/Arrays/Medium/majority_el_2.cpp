#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        // your code here
        // Moore's Voting Algorithm
        int el = 0;
        int cnt = 0;

        for (int i = 0; i < size; i++)
        {
            if (cnt == 0)
            {
                el = a[i];
                cnt++;
            }

            else if (el == a[i])
                cnt++;
            else
                cnt--;
        }

        int c = 0;
        for (int i = 0; i < size; i++)
        {
            if (el == a[i])
                c++;
        }

        if (c > size / 2)
            return el;
        return -1;
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
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}