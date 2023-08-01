#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        bool flag = true;
        bool checkZ = true;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
                checkZ = false;
        }
        // check for first m test cases (m=2) j=2,1
        for (int j = 0; j < m; j++)
        {
            if (arr[j] == 0)
            {
                flag = false;
            }
        }
        if (!checkZ)
        {
            if (!flag)
            {
                cout << "0" << endl;
            }
            else
            {
                cout << k << endl;
            }
        }
        else
        {
            cout << "100" << endl;
        }
    }
}