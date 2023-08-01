#include <iostream>
using namespace std;

int getNoOfWays(int n)
{
    if (n <= 2)

        return n;

    return getNoOfWays(n - 1) + getNoOfWays(n - 2);
}

int main()
{
    int n;
    cout << "Enter A Number : ";
    cin >> n;
    cout << "2X1 tiles can be placed in " << getNoOfWays(n) << " ways." << endl;
}