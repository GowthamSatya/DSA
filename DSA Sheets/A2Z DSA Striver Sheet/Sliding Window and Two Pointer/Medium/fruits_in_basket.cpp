#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalFruits(int N, vector<int> &fruits)
    {
        int ans = 1;
        int j = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < N; i++)
        {
            mp[fruits[i]]++;
            if (mp.size() <= 2)
                ans = max(ans, i - j + 1);

            while (mp.size() > 2)
            {
                mp[fruits[j]]--;
                if (mp[fruits[j]] == 0)
                    mp.erase(fruits[j]);
                j++;
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
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++)
            cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}
