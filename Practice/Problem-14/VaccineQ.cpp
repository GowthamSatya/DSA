#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    // 3
    while (t--)
    {
        int n, p, x, y, time = 0;
        cin >> n >> p >> x >> y;
        // 4 2 3 2
        int arr[n]; // arr[4]
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        // start iterating from p pos (2 ,1)
        for (int i = p; i > 0; i--)
        {
            // check for adult and add y mins
            if (arr[i - 1] == 1)
                time += y;
            // check for child and add x mins
            else if (arr[i - 1] == 0)
                time += x;
        }

        cout << time << endl;
    }
}