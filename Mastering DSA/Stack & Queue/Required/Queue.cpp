#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int size;
    int front, rear;
    vector<int> queue;

    int isEmpty()
    {
        return front == rear;
    }

    int isFull()
    {
        return rear == size - 1;
    }

public:
    Queue(int size)
    {
        this->size = size;
        front = -1;
        rear = -1;
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (front == -1)
            front += 1;
        rear++;
        queue.push_back(x);
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Empty" << endl;
            return -1;
        }

        int x = queue[front];
        front++;
        return x;
    }

    void display()
    {
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << endl;
    }
};

int main()
{
    Queue *q = new Queue(5);

    q->dequeue();

    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);

    q->display();
    q->enqueue(4);
    q->enqueue(5);
    q->enqueue(6);

    q->display();

    return 0;
}