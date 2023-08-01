#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // arr[] : the input array
    // N : size of the array arr[]

    // Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        // Your code here
        // sort(arr, arr + N);
        // int curr = -1, longest = 0, last_smaller = INT_MIN;

        // for (int i = 0; i < N; i++)
        // {
        //     if (arr[i] - 1 == last_smaller)
        //     {
        //         curr += 1;
        //         last_smaller = arr[i];
        //     }
        //     else if (last_smaller != arr[i])
        //     {
        //         curr = 1;
        //         last_smaller = arr[i];
        //     }

        //     longest = max(longest, curr);
        // }
        // return longest;

        // OPTIMAL APPROACH
        if (N == 0)
            return 0;

        int longest = 1;
        unordered_set<int> st;

        for (int i = 0; i < N; i++)
        {
            st.insert(arr[i]);
        }

        for (auto i : st)
        {
            if (st.find(i - 1) == st.end())
            {
                int cnt = 1;
                int x = i;

                while (st.find(x + 1) != st.end())
                {
                    x++;
                    cnt++;
                }

                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};

int main()
{
    int t, n, i, a[100001];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.findLongestConseqSubseq(a, n) << endl;
    }

    return 0;
}