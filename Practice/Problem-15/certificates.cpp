#include <iostream>
#define ll long long int
using namespace std;

int main()
{
    ll n, m, k;
    int count = 0;
    ll sum = 0;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        int arr[k + 1];
        for (int j = 0; j <= k; j++)
        {
            cin >> arr[j];
        }

        ll Q = arr[k];
        for (int t = 0; t < k; t++)
        {
            sum += arr[t];
        }

        if (sum >= m && Q <= 10)
            count++;
    }

    cout << count << endl;
}