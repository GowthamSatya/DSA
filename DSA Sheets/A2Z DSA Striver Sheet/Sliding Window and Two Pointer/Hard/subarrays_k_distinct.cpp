#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int atmost(vector<int> &a, int n, int m)
    {
        int ans = 0;
        int i = 0, j = 0;
        int cnt = 0;
        int freq[100001] = {0};
        while (j < n)
        {
            if (freq[a[j]] == 0)
            {
                cnt++;
            }
            freq[a[j]]++;
            while (cnt > m)
            {
                freq[a[i]]--;
                if (freq[a[i]] == 0)
                {
                    cnt--;
                }
                i++;
            }
            ans += (j - i + 1);
            j++;
        }
        return ans;
    }

public:
    int subarrayCount(vector<int> &arr, int N, int k)
    {
        // code here
        int t1 = atmost(arr, N, k);
        int t2 = atmost(arr, N, k - 1);
        int ans = t1 - t2;
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

        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution obj;
        cout << obj.subarrayCount(arr, N, k) << endl;
    }
    return 0;
}