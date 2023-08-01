#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        // code here
        stack<int> st;

        for (int i = 0; i < n; i++)
            st.push(i);

        while (st.size() > 1)
        {
            int a = st.top();
            st.pop();

            int b = st.top();
            st.pop();

            if (M[a][b] == 1)
                st.push(b);
            else
                st.push(a);
        }

        int temp = st.top();
        st.pop();

        for (int i = 0; i < n; i++)
        {
            if (i != temp)
            {
                if (M[i][temp] != 1)
                    return -1;
                if (M[temp][i] != 0)
                    return -1;
            }
        }

        return temp;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
}