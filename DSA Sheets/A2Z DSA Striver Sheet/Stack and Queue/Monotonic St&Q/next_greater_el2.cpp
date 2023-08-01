#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(int N, vector<int> &arr)
    {
        // code here

        stack<int> st;
        vector<int> ans;

        for (int i = 2 * N - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[i % N] >= st.top())
            {
                st.pop();
            }

            if (i < N)
            {
                if (st.empty())
                {
                    ans.push_back(-1);
                }
                else
                    ans.push_back(st.top());
            }

            st.push(arr[i % N]);
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
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution obj;
        vector<int> ans = obj.nextGreaterElement(N, arr);
        for (auto &it : ans)
        {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends