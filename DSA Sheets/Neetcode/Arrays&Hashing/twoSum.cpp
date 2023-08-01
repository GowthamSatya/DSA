#include <bits/stdc++.h>
using namespace std;

// Problem : https://leetcode.com/problems/two-sum/

vector<int> twoSum(vector<int> &nums, int target)
{
    int a = 0, b = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int temp = target - nums[i];

        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] == temp and j != i)
            {
                a = i, b = j;
                break;
            }
        }
    }
    return {a, b};
}