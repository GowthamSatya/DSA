#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool helper(int A[], int mid, int M, int N)
    {
        int pageSum = 0;
        int count = 1;
        for (int i = 0; i < N; i++)
        {
            if (A[i] > mid)
            {
                return false;
            }
            if (pageSum + A[i] > mid)
            {
                count++;
                pageSum = A[i];
                if (count > M)
                {
                    return false;
                }
            }
            else
            {
                pageSum = pageSum + A[i];
            }
        }
        return true;
    }

public:
    // Function to find minimum number of pages.
    int findPages(int A[], int N, int M)
    {
        // code here
        int mini = INT_MAX;
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            mini = min(mini, A[i]);
            sum += A[i];
        }

        if (N < M)
            return -1;

        int lo = mini;
        int hi = sum;
        int res = -1;

        while (lo <= hi)
        {
            int mid = (lo + hi) >> 1;

            bool ans = helper(A, mid, M, N);
            if (ans)
            {
                res = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }

        return res;
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
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}