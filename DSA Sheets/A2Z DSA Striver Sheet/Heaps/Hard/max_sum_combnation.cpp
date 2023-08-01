#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B)
    {
        // code here
        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end(), greater<int>());

        vector<int> ans;
        set<pair<int, int>> st;
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({A[0] + B[0], {0, 0}});

        for (int i = 0; i < K; i++)
        {
            pair<int, pair<int, int>> p = pq.top();
            pq.pop();

            ans.push_back(p.first);

            if (p.second.first + 1 < N && st.count({p.second.first + 1, p.second.second}) == 0)
            {
                pq.push({A[p.second.first + 1] + B[p.second.second], {p.second.first + 1, p.second.second}});
                st.insert({p.second.first + 1, p.second.second});
            }

            if (p.second.second + 1 < N && st.count({p.second.first, p.second.second + 1}) == 0)
            {
                pq.push({A[p.second.first] + B[p.second.second + 1], {p.second.first, p.second.second + 1}});
                st.insert({p.second.first, p.second.second + 1});
            }
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
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++)
        {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans)
            cout << it << ' ';
        cout << endl;
    }
    return 0;
}
