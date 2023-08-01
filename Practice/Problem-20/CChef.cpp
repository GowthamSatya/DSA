#include <iostream>
using namespace std;

int main()
{
    int t;
    long int n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int arr[2 * n];
        long int sum = 0;
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }

        if (sum % 2 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
