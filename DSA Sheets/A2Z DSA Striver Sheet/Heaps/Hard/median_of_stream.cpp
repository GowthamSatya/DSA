#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // maxHeap
    priority_queue<int> maxH;
    // minHeap
    priority_queue<int, vector<int>, greater<int>> minH;

public:
    // Function to insert heap.
    void insertHeap(int &x)
    {
        if (maxH.empty() || maxH.top() >= x)
            maxH.push(x);
        else
            minH.push(x);

        balanceHeaps();
    }

    // Function to balance heaps.
    void balanceHeaps()
    {
        if (maxH.size() > minH.size() + 1)
        {
            minH.push(maxH.top());
            maxH.pop();
        }
        else if (minH.size() > maxH.size())
        {
            maxH.push(minH.top());
            minH.pop();
        }
    }

    // Function to return Median.
    double getMedian()
    {
        if ((maxH.size() + minH.size()) & 1)
            return maxH.top();
        else
            return (double)(maxH.top() + minH.top()) / 2.0;
    }
};

int main()
{
    int n, x;
    int t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> x;
            ob.insertHeap(x);
            cout << floor(ob.getMedian()) << endl;
        }
    }
    return 0;
}