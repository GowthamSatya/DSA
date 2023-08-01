#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextSmallerElement(vector<int> &arr)
    {
        stack<int> s;
        s.push(-1);

        vector<int> ans(arr.size());

        for (int i = arr.size() - 1; i >= 0; i--)
        {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr)
                s.pop();

            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int> &arr)
    {
        stack<int> s;
        s.push(-1);

        vector<int> ans(arr.size());

        for (int i = 0; i < arr.size(); i++)
        {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr)
                s.pop();

            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();

        vector<int> next(n);
        next = nextSmallerElement(heights);

        vector<int> prev(n);
        prev = prevSmallerElement(heights);
        int area = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int l = heights[i];
            if (next[i] == -1)
                next[i] = n;
            int b = next[i] - prev[i] - 1;

            int newArea = l * b;
            area = max(area, newArea);
        }

        return area;
    }
};