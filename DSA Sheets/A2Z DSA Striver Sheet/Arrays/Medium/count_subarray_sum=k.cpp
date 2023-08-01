#include <bits/stdc++.h>
using namespace std;

int findAllSubarraysWithGivenSum(vector<int> &arr, int k)
{
    // Write Your Code Here

    // to store the sums of previous elements
    map<int, int> preSum;

    // to get the current sum
    int sum = 0;

    // final count of subarrays
    int cnt = 0;

    // start with index 0 if array is empty;
    preSum[0] = 1;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        // if there is a prev sum with sum-k then  add its count to the cnt
        cnt += preSum[sum - k];

        // increase the count of that particular sum
        preSum[sum] += 1;
    }

    return cnt;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int ans = findAllSubarraysWithGivenSum(arr, k);
        cout << ans << endl;
    }

    return 0;
}