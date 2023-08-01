#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    long int a, b, c, d, k;
    while (t--)
    {
        cin >> a >> b >> c >> d >> k;
        long int xc = 0, yc = 0;
        // a=1 c=2 1+1
        long int dist = abs(c - a) + abs(d - b);

        if (k < dist)
            cout << "NO" << endl;
        else if (dist == k)
            cout << "YES" << endl;
        else
        {
            if (k % 2 == dist % 2)
            {
                cout << "YES" << endl;
            }
            else
                cout << "NO" << endl;
        }
    }
}