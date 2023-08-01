//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<int> AllPrimeFactors(int N)
    {
        // Code here
        vector<int> ans;

        while (N > 1)
        {
            for (int i = 2; i <= N; i++)
            {
                if (N % i == 0)
                {
                    ans.push_back(i);
                    N /= i;
                    break;
                }
            }
        }

        set<int> st(ans.begin(), ans.end());
        vector<int> res(st.begin(), st.end());

        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        long long int N;
        cin >> N;
        Solution ob;
        vector<int> ans = ob.AllPrimeFactors(N);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends