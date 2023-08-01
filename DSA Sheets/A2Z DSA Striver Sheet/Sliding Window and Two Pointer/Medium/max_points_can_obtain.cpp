#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxScore(vector<int> &cardPoints, int N, int k)
    {
        // code here
        int i = 0;
        vector<int> sums;
        int ans = -1;
        for (auto i : cardPoints)
        {
            if (sums.size() > 0)
            {
                sums.push_back(sums.back() + i);
            }
            else
            {
                sums.push_back(i);
            }
        }

        if (k == N)
            return sums.back();

        for (int i = 0; i <= k; i++)
        {
            int j = i + cardPoints.size() - k - 1;
            int temp = 0;
            if (i > 0)
                temp = sums[j] - sums[i - 1];
            else
                temp = sums[j];
            ans = max(ans, sums.back() - temp);
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
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++)
            cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}