#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

double fractionalKnapsack(int W, set<pair<int, int>> &arr)
{

    int currentWeight = 0;
    double finalValue = 0;

    for (auto const &i : arr)
    {
        cout << i.first << " " << i.second << endl;
        if (currentWeight + i.second <= W)
        {
            currentWeight += i.second;
            finalValue += i.first;
        }
        else
        {
            double remainingWeight = W - currentWeight;
            finalValue += i.first * ((double)remainingWeight / (double)i.second);
            break;
        }
    }

    return finalValue;
}

int main()
{
    int W, n;

    cout << "Enter Max Weight : ";
    cin >> W;
    cout << "Enter Number of Knapsacks : ";
    cin >> n;
    set<pair<int, int>> s;

    for (int i = 0; i < n; i++)
    {
        int value, weight;
        cout << "Enter Knapsack " << i + 1 << " Data (Value, Weight)  : ";
        cin >> value >> weight;
        pair<int, int> p = make_pair(value, weight);
        s.insert(p);
    }

    cout << "Max Value (Profit) is : " << fractionalKnapsack(W, s) << endl;
}