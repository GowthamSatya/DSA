#include <bits/stdc++.h>
using namespace std;

// Problem : https://leetcode.com/problems/contains-duplicate/

bool containsDuplicate(vector<int> &nums)
{
    map<int, int> m;

    for (auto i : nums)
        m[i]++;

    for (auto i : m)
        if (i.second > 1)
            return true;
    return false;
}

bool containsDuplicate(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i - 1] == nums[i])
            return true;
    }
    return false;
}

bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> s;
    for (int i = 0; i < nums.size(); i++)
    {
        if (s.count(nums[i]))
            return true;
        s.insert(nums[i]);
    }
    return false;
}
