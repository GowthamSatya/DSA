#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        // code here
        priority_queue<int, vector<int>, greater<int>> minH;
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            minH.push(arr[i]);

            while (minH.size() > k)
            {
                minH.pop();
            }
        }

        while (minH.size() > 0)
        {
            ans.push_back(minH.top());
            minH.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        vector<int> result = ob.kLargest(arr, n, k);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
