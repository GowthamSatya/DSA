//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int KthMissingElement(int a[], int n, int k);

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout << KthMissingElement(a, n, k) << endl;
    }
    return 0;
}

int KthMissingElement(int a[], int n, int k)
{
    // Complete the function
    int kthMissEle = -1, kthCount = 0, minEle = a[0], maxEle = a[n - 1];
    int range = maxEle - minEle + 1;
    int tempArr[range] = {0};
    for (int i = 0; i < n; ++i)
    {
        tempArr[a[i] - minEle] = 1;
    }
    for (int i = 0; i < range; ++i)
    {
        if (tempArr[i] != 1)
        {
            ++kthCount;
            if (kthCount == k)
            {
                kthMissEle = i + minEle;
            }
        }
    }
    return kthMissEle;
}