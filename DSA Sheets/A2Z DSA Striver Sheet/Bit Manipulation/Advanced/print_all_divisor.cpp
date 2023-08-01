#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void print_divisors(int n)
    {
        // Code here.
        set<int> s;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                s.insert(i);
                if ((n / i) != i)
                    s.insert(n / i);
            }
        }

        for (auto st : s)
            cout << st << " ";
    }
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        Solution ob;
        ob.print_divisors(n);
        cout << endl;
    }
    return 0;
}