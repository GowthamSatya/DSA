#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int size;
    int top;
    vector<int> stack;

    int isEmpty()
    {
        return top == -1;
    }

    int isFull()
    {
        return top == size - 1;
    }

public:
    Stack(int size)
    {
        this->size = size;
        top = -1;
    }

    void push(int x)
    {
        if (isFull())
        {
            cout << "stack overflow";
            return;
        }
        top++;
        stack.push_back(x);
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "stack underflow";
            return -1;
        }
        int x = stack[top];
        top--;
        stack.pop_back();
        return x;
    }

    int get_top()
    {
        return stack[top];
    }

    void display()
    {
        for (auto i : stack)
            cout << i << " ";
        cout << endl;
    }
};

int main()
{
    Stack *s = new Stack(5);
    s->push(1);
    s->push(2);
    s->display();
    int x = s->pop();
    cout << x << endl;

    s->display();
}