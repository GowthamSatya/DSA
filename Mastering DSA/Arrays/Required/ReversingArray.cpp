#include <bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int n)
{
    for (int i = 0; i < (n / 2 + n % 2); i++)
        swap(arr[i], arr[n - i - 1]);

    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}

int main()
{
    int arr[4] = {4, 5, 1, 3};
    reverseArray(arr, 4);
    return 0;
}