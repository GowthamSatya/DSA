//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void _3Sum(vector<int> &arr, int N)
    {
        // code here
        sort(arr.begin(), arr.end());
        set<vector<int>> res;

        for (int i = 0; i < N; i++)
        {
            int temp = arr[i];
            int lo = i + 1;
            int hi = N - 1;

            while (lo <= hi)
            {
                if (arr[lo] + arr[hi] == -temp)
                {
                    res.insert({temp, arr[lo], arr[hi]});
                }
                else if ((arr[lo] + arr[hi]) > temp)
                    hi--;
                else
                    lo++;
            }
        }

        for (auto i : res)
        {
            cout << i[0] << " " << i[1] << " " << i[2] << endl;
        }
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
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution obj;
        obj._3Sum(arr, N);
    }
    return 0;
}
// } Driver Code Ends