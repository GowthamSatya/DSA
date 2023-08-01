#include <iostream>
#define ll long long int
using namespace std;

int main()
{
    ll D, L, R;
    int T;
    cin >> T;
    while (T--)
    {
        cin >> D >> L >> R;
        if (L <= D && R >= D)
            cout << "Take second dose now" << endl;
        else if (L <= D && R <= D)
            cout << "Too Late" << endl;
        else
            cout << "Too Early" << endl;
    }
}