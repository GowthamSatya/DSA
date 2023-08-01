#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int arr2[1001] = {0};
        for (int i = 1000; i >= 0; i--)
        {
            arr2[arr[i]]++;
        }

        int area = 1;
        bool flag = false;
        for (int i = 1000; i >= 0; i--)
        {
            if (!flag)
            {
                if (arr2[i] >= 2)
                {
                    area *= i;
                    arr2[i] -= 2;
                    flag = true;
                }
            }
            if (flag)
            {
                if (arr2[i] >= 2)
                {
                    area *= i;
                    flag = false;
                    break;
                }
            }
        }

        cout << area << endl;
    }
    return 0;
}
