#include <bits/stdc++.h>
using namespace std;

// Problem : https://leetcode.com/problems/top-k-frequent-elements/

vector<int> topKFrequent(vector<int> &nums, int k)
{
    map<int, int> m;
    vector<int> out;
    vector<pair<int, int>> s;

    for (int i = 0; i < nums.size(); i++)
        m[nums[i]]++;

    for (auto i : m)
        s.push_back({i.second, i.first});

    sort(s.begin(), s.end(), greater<pair<int, int>>());

    for (int i = 0; i < min(k, int(s.size())); i++)
        out.push_back(s[i].second);

    return out;
}
