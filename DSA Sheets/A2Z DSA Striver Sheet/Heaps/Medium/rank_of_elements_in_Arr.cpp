#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef pair<int, int> pi;
    vector<int> replaceWithRank(vector<int> &arr, int N)
    {
        priority_queue<pi, vector<pi>, greater<pi>> pq;

        for (int i = 0; i < N; i++)
            pq.push({arr[i], i});

        int cnt = 1;

        while (!pq.empty())
        {
            auto p = pq.top();
            pq.pop();

            arr[p.second] = cnt;

            // update the rank when both elements are different
            if (!pq.empty() && (pq.top().first != p.first))
            {
                cnt++;
            }
        }

        return arr;
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
        vector<int> vec(n);
        for (int i = 0; i < n; i++)
            cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec, n);
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}