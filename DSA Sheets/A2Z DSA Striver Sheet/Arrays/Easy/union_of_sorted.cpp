#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // arr1,arr2 : the arrays
    //  n, m: size of arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        // return vector with correct order of elements
        // Two Pointer Approach
        vector<int> uni;

        int i = 0, j = 0;
        while (i < n && j < m)
        {
            // if the arr1[i] is smaller
            if (arr1[i] <= arr2[j])
            {
                // check for duplicates
                if (uni.size() == 0 || uni.back() != arr1[i])
                    uni.push_back(arr1[i]);
                i++;
            }
            else
            {
                if (uni.size() == 0 || uni.back() != arr2[j])
                    uni.push_back(arr2[j]);
                j++;
            }
        }

        // push all the remaining elements in both arrays
        while (i < n)
        {
            if (uni.size() == 0 || uni.back() != arr1[i])
                uni.push_back(arr1[i]);
            i++;
        }

        while (j < m)
        {
            if (uni.size() == 0 || uni.back() != arr2[j])
                uni.push_back(arr2[j]);
            j++;
        }

        return uni;
    }
};

int main()
{

    int T;
    cin >> T;

    while (T--)
    {

        int N, M;
        cin >> N >> M;

        int arr1[N];
        int arr2[M];

        for (int i = 0; i < N; i++)
        {
            cin >> arr1[i];
        }

        for (int i = 0; i < M; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        vector<int> ans = ob.findUnion(arr1, arr2, N, M);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}