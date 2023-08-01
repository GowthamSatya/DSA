#include <bits/stdc++.h>
using namespace std;

string get_perms(int n, int k)
{
    int fact = 1;
    vector<int> numbers;
    // calculating factorials and storing the numbers
    for (int i = 1; i < n; i++)
    {
        fact = fact * i;
        numbers.push_back(i);
    }

    numbers.push_back(n);
    string ans = "";
    k -= 1;
    while (true)
    {
        ans += to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + k / fact);
        if (numbers.size() == 0)
            break;

        k %= fact;
        fact /= numbers.size();
    }

    return ans;
}

int main()
{
    int k = 17;
    int n = 4;

    cout << get_perms(n, k);

    return 0;
}