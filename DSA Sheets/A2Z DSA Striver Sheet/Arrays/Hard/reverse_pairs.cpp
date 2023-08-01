//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    long long cnt = 0;
    void merge(vector<int> &arr, int lo, int mid, int hi)
    {
        vector<int> temp;
        int l = lo;
        int r = mid + 1;

        while (l <= mid && r <= hi)
        {
            if (arr[l] < arr[r])
                temp.push_back(arr[l++]);
            else
                temp.push_back(arr[r++]);
        }

        while (l <= mid)
            temp.push_back(arr[l++]);
        while (r <= hi)
            temp.push_back(arr[r++]);

        for (int i = lo; i <= hi; i++)
            arr[i] = temp[i - lo];
    }

    void countPairs(vector<int> &arr, int lo, int mid, int hi)
    {
        int right = mid + 1;
        for (int i = lo; i <= mid; i++)
        {
            while (right <= hi && arr[i] > 2 * arr[right])
                right++;
            cnt = cnt + (right - (mid + 1));
        }
    }

    void mergeSort(vector<int> &arr, int lo, int hi)
    {
        if (lo >= hi)
            return;

        int mid = (lo + hi) / 2;

        mergeSort(arr, lo, mid);
        mergeSort(arr, mid + 1, hi);
        countPairs(arr, lo, mid, hi);
        merge(arr, lo, mid, hi);
    }

public:
    int countRevPairs(int n, vector<int> arr)
    {
        // Code here
        mergeSort(arr, 0, n - 1);
        return cnt;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends