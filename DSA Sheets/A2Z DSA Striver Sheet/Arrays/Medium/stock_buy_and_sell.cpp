#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, i;
        cin >> n;
        int price[n];
        for (i = 0; i < n; i++)
            cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}

void stockBuySell(int price[], int n)
{
    // buy first
    int mini = price[0];
    int ans = -1;

    for (int i = 1; i < n; i++)
    {
        // if you sell at day i
        // calculate the cost of selling
        // update the ans accordingly
        int cost = price[i] - mini;
        ans = max(ans, cost);
        // if the price[i] is smaller than the current buying price
        // update the current buying price to it
        mini = min(mini, price[i]);
    }

    cout << ans << endl;
}