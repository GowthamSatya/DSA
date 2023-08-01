#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void heapify(vector<int> &arr, int idx)
    {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int smallest = idx;

        int n = arr.size();

        if (left < n && arr[left] > arr[smallest])
            smallest = left;
        if (right < n && arr[right] > arr[smallest])
            smallest = right;

        if (smallest != idx)
        {
            swap(arr[smallest], arr[idx]);
            heapify(arr, smallest);
        }
    }

public:
    void convertMinToMaxHeap(vector<int> &arr, int N)
    {

        for (int i = (N - 2) / 2; i >= 0; i--)
            heapify(arr, i);
    }
};

int main()
{
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--)
    {
        // Input

        int n;
        cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; i++)
            cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec, n);
        for (int i = 0; i < n; i++)
            cout << vec[i] << " ";
        cout << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}