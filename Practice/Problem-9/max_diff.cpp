#include <iostream>
#define li long int
using namespace std;

int main()
{
    int T;
    cin >> T;
    li N, S;
    while (T--)
    {
        cin >> N >> S;
        if (N >= S)
        {
            cout << S << endl;
        }
        else
        {
            cout << 2 * N - S << endl;
        }
    }
    // your code goes here
    return 0;
}
