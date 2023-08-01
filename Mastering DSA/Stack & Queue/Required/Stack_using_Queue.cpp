#include <bits/stdc++.h>
using namespace std;

class Stack_Queue
{
    queue<int> q;

public:
    void push(int x)
    {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int st_pop()
    {
        int t = q.front();
        q.pop();
        return t;
    }

    void top()
    {
        cout << q.front() << endl;
    }

    void display()
    {
        queue<int> temp = q;
        while (!temp.empty())
        {
            int t = temp.front();
            cout << t << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main()
{
    Stack_Queue sq;
    sq.push(10);
    sq.display();
    sq.push(11);
    sq.push(12);
    sq.display();
    sq.top();
    sq.st_pop();
    sq.display();
    sq.st_pop();
    sq.display();

    return 0;
}