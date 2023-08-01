#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        stack<long long> st;
        long long maxArea = 0;

        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || arr[i] <= arr[st.top()]))
            {
                long long h = arr[st.top()];
                st.pop();

                long long w;
                if (st.empty())
                    w = i;
                else
                    w = i - st.top() - 1;

                maxArea = max(maxArea, w * h);
            }
            st.push(i);
        }

        return maxArea;
    }
};

int main()
{
    long long t;

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr, n) << endl;
    }
    return 0;
}