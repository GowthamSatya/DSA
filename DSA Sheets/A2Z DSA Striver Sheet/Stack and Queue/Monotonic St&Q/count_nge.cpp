#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices)
    {
        // write your code here

        vector<int> res;

        for (int i = 0; i < indices.size(); i++)
        {
            int cnt = 0;

            for (int j = indices[i] + 1; j < n; j++)
            {
                if (arr[j] > arr[indices[i]])
                    cnt++;
            }
            res.push_back(cnt);
        }

        return res;
    }
};

int main()
{
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--)
    {
        // Input

        int n;
        cin >> n;
        vector<int> v1(n);
        for (int i = 0; i < n; i++)
            cin >> v1[i];
        int q;
        cin >> q;
        vector<int> v2(q);
        for (int i = 0; i < q; i++)
            cin >> v2[i];

        Solution obj;
        vector<int> ans = obj.count_NGE(n, v1, q, v2);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends