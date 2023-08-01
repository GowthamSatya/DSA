#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lenOfLongSubarr(int A[], int N, int K)
    {
        // map to store the sum and length of the subarray
        map<int, int> preMap;
        long long sum = 0;

        int maxi = 0;

        for (int i = 0; i < N; i++)
        {
            sum += A[i];

            // if the sum == k then update the answer
            if (sum == K)
                maxi = max(maxi, i + 1);

            int rem = sum - K;
            // check in map if we find a sum wit h (currSum-k)
            // if yes we found an another subarray with sum K
            // check the length of this subarry ans update if necessary
            if (preMap.find(rem) != preMap.end())
            {
                int len = i - preMap[rem];
                maxi = max(maxi, len);
            }

            // if not present in the map then update the map
            if (preMap.find(sum) == preMap.end())
                preMap[sum] = i;
        }

        return maxi;

        // Best Approach for positives and zeros;
        // Sliding window technique
        // as the sum increases as we go further there is no point in storing the totalSum

        // int l = 0, r =0;
        // int sum = A[0];
        // int maxLen = 0;

        // while(r <N){
        //     while(l<=r && sum > K){
        //         sum -= A[l];
        //         l++;
        //     }
        //     if(sum == K) maxLen = max(maxLen, r-l+1);
        //     r++;
        //     if(r < N) sum += A[r];
        // }

        // return maxLen;
    }
};

int main()
{
    // code

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.lenOfLongSubarr(a, n, k) << endl;
    }

    return 0;
}