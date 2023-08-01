#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextPermutation(int N, vector<int> arr)
    {
        // code here

        // c++ stl
        // next_permutation(arr.begin(), arr.end());
        // return arr;

        // init the index
        int idx = -1;

        // find the breakpoint where the element is smaller than the next element
        for (int i = N - 2; i >= 0; i--)
        {
            if (arr[i] < arr[i + 1])
            {
                idx = i;
                break;
            }
        }

        // if no bp found then no next permutation
        // reverse the array and return
        if (idx == -1)
        {
            reverse(arr.begin(), arr.end());
            return arr;
        }

        // if there is a break point
        // find the smallest value before the break point to end
        // and swap it with the element at the breakpoint
        for (int i = N - 1; i > idx; i--)
        {
            if (arr[i] > arr[idx])
            {
                swap(arr[i], arr[idx]);
                break;
            }
        }

        // reverse the array after the breakpoint and return
        reverse(arr.begin() + idx + 1, arr.end());
        return arr;
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
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for (int u : ans)
            cout << u << " ";
        cout << "\n";
    }
    return 0;
}