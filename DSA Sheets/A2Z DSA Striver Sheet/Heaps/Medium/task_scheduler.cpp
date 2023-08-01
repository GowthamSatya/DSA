#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int leastInterval(int N, int K, vector<char> &tasks)
    {
        // code here
        vector<int> freq(26, 0);

        for (auto i : tasks)
            freq[i - 'A']++;

        sort(freq.begin(), freq.end());
        int last = freq[25] - 1;
        int idleSpots = last * K;

        for (int i = 24; i >= 0; i--)
        {
            idleSpots -= min(last, freq[i]);
        }

        return idleSpots < 0 ? tasks.size() : (idleSpots + tasks.size());
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

        vector<char> tasks(N);
        for (int i = 0; i < N; i++)
            cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}