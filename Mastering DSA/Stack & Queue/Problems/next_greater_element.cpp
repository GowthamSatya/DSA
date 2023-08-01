#include <bits/stdc++.h>
using namespace std;

vector<int> nge(vector<int> &arr)
{
    vector<int> nge;
    stack<int> st;
    int n = arr.size();

    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i % n])
        {
            st.pop();
        }
        if (i < n)
        {
            if (!st.empty())
            {
                nge.push_back(st.top());
            }
            else
                nge.push_back(-1);
        }
        st.push(arr[i % n]);
    }
    return nge;
}

int main()
{
    vector<int> arr = {2, 10, 1, 12, 11};
    vector<int> ans = nge(arr);

    for (auto i : ans)
        cout << i << " ";
    return 0;
}