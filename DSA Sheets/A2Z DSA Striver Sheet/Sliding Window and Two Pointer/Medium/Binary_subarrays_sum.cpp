#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubarrays(vector<int> &arr, int N, int target)
    {
        // code here
        unordered_map<int, int> mp;
        int sum = 0, cnt = 0;

        for (int i = 0; i < N; i++)
        {
            sum += arr[i];

            if (sum == target)
                cnt++;

            if (mp.find(sum - target) != mp.end())
                cnt += mp[sum - target];

            mp[sum]++;
        }

        return cnt;
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
        int target;
        cin >> target;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.numberOfSubarrays(arr, N, target) << endl;
    }
    return 0;
}