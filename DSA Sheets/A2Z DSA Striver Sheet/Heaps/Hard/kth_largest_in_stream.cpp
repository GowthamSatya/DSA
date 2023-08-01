#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> kthLargest(int k, int arr[], int n)
    {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> ans(n, 0);

        for (int i = 0; i < k; i++)
        {
            pq.push(arr[i]);
            ans[i] = -1;
        }

        ans[k - 1] = pq.top();
        for (int i = k; i < n; i++)
        {
            if (pq.top() < arr[i])
            {
                pq.pop();
                pq.push(arr[i]);
            }
            ans[i] = pq.top();
        }

        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k, n;
        cin >> k >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k, arr, n);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}