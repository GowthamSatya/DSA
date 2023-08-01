#include <iostream>

using namespace std;

class Sum
{
private:
    static int a, b, c;
    int sum;

public:
    Sum()
    {
        Sum::a = 5;
        Sum::b = 5;
        Sum::c = 5;
        sum = (a + b + c);
    }
    int printSum(int a, int b, int c);
    int printSum(int a, int b);
    void printSum();
};

void Sum::printSum()
{
    cout << sum << endl;
}

int Sum::printSum(int a, int b, int c)
{
    return ((a + b + c) + (Sum::a + Sum::b));
}

int Sum::printSum(int a, int b)
{
    return (a + b);
}

int main()
{
    Sum s1;
    s1.printSum();
    int sum1 = s1.printSum(1, 2);
    int sum2 = s1.printSum(1, 2, 3);

    cout << sum1 << " " << sum2 << endl;

    return 0;
}