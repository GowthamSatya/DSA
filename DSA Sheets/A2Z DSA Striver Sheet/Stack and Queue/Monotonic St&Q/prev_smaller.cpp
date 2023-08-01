#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> prevSmaller(vector<int> &);
};

vector<int> Solution::prevSmaller(vector<int> &A)
{
    stack<int> st;
    vector<int> ans;
    for (int i = 0; i < A.size(); i++)
    {
        while (!st.empty() && A[i] <= st.top())
            st.pop();

        if (st.empty())
            ans.push_back(-1);
        else
            ans.push_back(st.top());
        st.push(A[i]);
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Solution sol;
    vector<int> ans = sol.prevSmaller(arr);

    for (auto i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}