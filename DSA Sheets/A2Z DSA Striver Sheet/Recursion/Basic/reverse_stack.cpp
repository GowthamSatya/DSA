#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void insert(stack<int> &s, int temp)
    {
        if (s.empty())
        {
            s.push(temp);
            return;
        }

        int el = s.top();
        s.pop();
        insert(s, temp);
        s.push(el);
        return;
    }

public:
    void Reverse(stack<int> &St)
    {
        if (St.size() == 1)
            return;

        int temp = St.top();
        St.pop();

        Reverse(St);
        insert(St, temp);
        return;
    }
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        stack<int> St;
        for (int i = 0; i < N; i++)
        {
            int x;
            cin >> x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int> res;
        while (St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for (int i = res.size() - 1; i >= 0; i--)
        {
            cout << res[i] << " ";
        }

        cout << endl;
    }
}