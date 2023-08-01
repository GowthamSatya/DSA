//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    int getMaxArea(int arr[], int n)
    {
        // Your code here
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || arr[i] <= arr[st.top()]))
            {
                int h = arr[st.top()];
                st.pop();

                int w;
                if (st.empty())
                    w = i;
                else
                    w = i - st.top() - 1;

                maxArea = max(maxArea, w * h);
            }
            st.push(i);
        }

        return maxArea;
    }

public:
    int maxArea(int M[MAX][MAX], int n, int m)
    {
        int area = getMaxArea(M[0], m);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (M[i - 1][j] == 1 && M[i][j] == 1)
                {
                    M[i][j] += M[i - 1][j];
                }
            }
            area = max(area, getMaxArea(M[i], m));
        }

        return area;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends