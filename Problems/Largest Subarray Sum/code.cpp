#include <bits/stdc++.h>
using namespace std;

int getMaxSum(int arr[], int n)
{
    int a = INT_MIN;
    int b = 0, st = 0, e = 0;
    int s = 0;

    for (int i = 0; i < n; i++)
    {
        b = b + arr[i];
        if (a < b)
        {
            a = b;
            st = s;
            e = i;
        }

        if (b < 0)
        {
            b = 0;
            s = i + 1;
        }
    }
    cout << "Start : " << st << ", end : " << e << endl;
    return a;
}

// Kadane's Algorithm
int main()
{
    int arr[8] = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << getMaxSum(arr, 8) << endl;
    return 0;
}