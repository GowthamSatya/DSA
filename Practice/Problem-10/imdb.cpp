#include <iostream>
#define ll long long int
using namespace std;

int main()
{
    int T;
    cin >> T;
    ll N, X, S, R, temp = 0;
    while (T--)
    {
        cin >> N >> X;
        while (N--)
        {
            cin >> S >> R;
            if (X >= S)
            {
                if (R > temp)
                {
                    temp = R;
                }
            }
        }
        cout << temp << endl;
        temp = 0;
    }
}