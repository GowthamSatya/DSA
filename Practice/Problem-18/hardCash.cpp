#include <iostream>
#define ll long long int
using namespace std;

int main()
{
    ll t;
    cin >> t;
    ll sum = 0;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        // n=5 k=7
        // arr= {1, 14, 4,41,1}

        for (auto i : arr)
        {
            sum += arr[i];
        }

        cout << sum % k << endl;
    }
}