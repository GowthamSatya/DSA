#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsertK(vector<int> Arr, int N, int k)
    {
        // code here
        int lo = 0, hi = N - 1;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            if (Arr[mid] == k)
            {
                return mid;
            }
            else if (Arr[mid] < k)
            {
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }

        return lo;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> Arr(N);
        for (int i = 0; i < N; i++)
            cin >> Arr[i];
        int k;
        cin >> k;
        Solution obj;
        cout << obj.searchInsertK(Arr, N, k) << endl;
    }
    return 0;
}