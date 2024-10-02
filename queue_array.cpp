#include <iostream>
using namespace std;
const int SIZE = 5;
class Queue
{
    int items[SIZE], front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    bool isFull()
    {
        if (front == 0 && rear == SIZE - 1)
        {
            return true;
        }
        return false;
    }
    bool isEmpty()
    {
        if (front < 0)
        {
            return true;
        }
        return false;
    }
    void enQueue(int val)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            if (front == -1)
            {
                front = 0;
            }
            // rear++;
            items[++rear] = val;
            cout << "Inserted " << val << " and index is " << rear + 1 << endl;
        }
    }
    int deQueue()
    {
        int val;
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
        {
            val = items[front++];
            // front++;
            if (front > rear)
            {
                front = rear = -1;
            }
            cout << "Deleted " << val << endl;
            return val;
        }
    }
    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
        {
            cout << "Peeked " << items[front] << "and index is " << rear + 1 << endl;
            return items[front];
        }
    }
};

int main()
{
    Queue q;

    q.peek();

    return 0;
}