#include <bits/stdc++.h>
using namespace std;

int max_profit(vector<int> &arr)
{
    int left = 0;  // buy
    int right = 1; // sell

    int max_profit = 0, curr_diff = 0;

    while (right < arr.size())
    {
        if (arr[left] > arr[right])
        {
            left = right;
            right++;
        }
        else
        {
            curr_diff = arr[right] - arr[left];
            max_profit = max(max_profit, curr_diff);
            right++;
        }
    }
    return max_profit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << max_profit(prices) << endl;

    return 0;
}