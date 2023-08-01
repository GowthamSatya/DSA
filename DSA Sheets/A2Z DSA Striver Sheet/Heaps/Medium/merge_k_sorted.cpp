#include <bits/stdc++.h>
#define N 105
using namespace std;

void printArray(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

class Solution
{
    void heapify(vector<int> &arr, int n, int i)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int small = i;

        if (l < n && arr[l] > arr[small])
            small = l;
        if (r < n && arr[r] > arr[small])
            small = r;

        if (small != i)
        {
            swap(arr[small], arr[i]);
            heapify(arr, n, small);
        }
    }

    void buildHeap(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = (n / 2) - 1; i >= 0; i--)
            heapify(arr, n, i);
    }

    void heapSort(vector<int> &arr)
    {
        buildHeap(arr);
        int n = arr.size();

        for (int i = n - 1; i >= 0; i--)
        {
            swap(arr[i], arr[0]);
            heapify(arr, i, 0);
        }
    }

public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        // code here
        vector<int> ans;
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans.push_back(arr[i][j]);
            }
        }

        heapSort(ans);

        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        vector<vector<int>> arr(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution obj;
        vector<int> output = obj.mergeKArrays(arr, k);
        printArray(output, k * k);
        cout << endl;
    }
    return 0;
}