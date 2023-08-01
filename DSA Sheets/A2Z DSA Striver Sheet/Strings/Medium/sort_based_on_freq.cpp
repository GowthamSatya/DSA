#include <bits/stdc++.h>
#include <string>
using namespace std;

vector<int> getSorted(vector<int> &A)
{
    map<int, int> m;
    vector<int> ans;

    for (auto i : A)
        m[i]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;

    for (auto i : m)
    {
        pq.push({i.second, -1 * i.first});
    }

    while (!pq.empty())
    {
        int fre = pq.top().first;
        int el = pq.top().second;

        for (int i = 0; i < fre; i++)
            ans.push_back(-1 * el);
        pq.pop();
    }

    return ans;
}

int main()
{
    // code
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        vector<int> ans = getSorted(arr);

        for (auto i : ans)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}