#include <bits/stdc++.h>
using namespace std;

class Solution
{
    long long merge(long long arr[], int lo, int mid, int hi)
    {
        long long cnt = 0;
        vector<int> temp;
        int l = lo;
        int r = mid + 1;

        while (l <= mid && r <= hi)
        {
            if (arr[l] <= arr[r])
                temp.push_back(arr[l++]);
            // right is smaller
            else
            {
                cnt += mid - l + 1;
                temp.push_back(arr[r++]);
            }
        }

        while (l <= mid)
            temp.push_back(arr[l++]);
        while (r <= hi)
            temp.push_back(arr[r++]);

        for (int i = lo; i <= hi; i++)
            arr[i] = temp[i - lo];

        return cnt;
    }

    long long mergeSort(long long arr[], int lo, int hi)
    {
        long long cnt = 0;
        if (lo >= hi)
            return 0;

        int mid = (lo + hi) / 2;

        cnt += mergeSort(arr, lo, mid);
        cnt += mergeSort(arr, mid + 1, hi);
        cnt += merge(arr, lo, mid, hi);
        return cnt;
    }

public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return mergeSort(arr, 0, N - 1);
    }
};

int main()
{

    long long T;
    cin >> T;

    while (T--)
    {
        long long N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}