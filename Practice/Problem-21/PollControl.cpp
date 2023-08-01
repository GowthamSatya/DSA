#include <iostream>
using namespace std;

int min(int a, int b, int c)
{
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int main()
{
    int t, n, x, y;
    cin >> t;

    while (t--)
    {
        int car = 0, bus = 0, both = 0;
        cin >> n >> x >> y;
        int n1 = n;
        int n2 = n;
        int n3 = n;

        while (n1 > 0)
        {
            n1 = n1 - 100;
            bus = bus + 1;
        }

        while (n2 > 0)
        {
            n2 -= 4;
            car += 1;
        }

        while (n3 > 0)
        {
            if (n3 >= 100)
            {
                n3 -= 100;
                both += x;
            }
            else
            {
                n3 -= 4;
                both += y;
            }
        }
        cout << min(bus * x, car * y, both) << endl;
    }
}