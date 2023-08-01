#include <bits/stdc++.h>
using namespace std;

class Queue_Stack
{
    stack<int> ip, op;

public:
    void enqueue(int x)
    {
        ip.push(x);
    }

    int dequeue()
    {
        if (op.empty() == 0)
        {
            int x = op.top();
            op.pop();
            return x;
        }
        else
        {
            while (!ip.empty())
            {
                int x = ip.top();
                ip.pop();
                op.push(x);
            }
            int x = op.top();
            op.pop();
            return x;
        }
    }

    void top()
    {
        if (!op.empty())
        {
            cout << op.top() << endl;
        }
        else
        {
            while (!ip.empty())
            {
                int x = ip.top();
                ip.pop();
                op.push(x);
            }
            int x = op.top();
            cout << x << endl;
        }
    }

    void display()
    {
        while (!ip.empty())
        {
            int x = ip.top();
            ip.pop();
            op.push(x);
        }
        stack<int> temp = op;
        while (!temp.empty())
        {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main()
{
    Queue_Stack qs;
    qs.enqueue(10);
    qs.enqueue(15);
    qs.display();
    qs.top();
    qs.dequeue();
    qs.display();
    return 0;
}