#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
class Queue
{
    Node *front;
    Node *rear;
    int size;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
        size = 1;
    }
    void enQueue(int val)
    {
        Node *n = new Node(val);
        if (front == NULL)
        {
            front = rear = n;
            cout << "Inserted: " << val << "  and size is " << size << endl;
        }
        else
        {

            cout << "Inserted: " << val << "  and size is " << ++size << endl;
            rear->next = n;
            rear = n;
        }
    }
    void deQueue()
    {
        if (front == NULL)
        {
            cout << "Queue is empty " << endl;
        }
        else
        {
            Node *toDelete = front;
            front = front->next;
            cout << "Deleted: " << toDelete->data << " and size is " << --size << endl;
            delete toDelete;
        }
    }
    int peek()
    {
        if (front == NULL)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        cout << "Peeked: " << front->data << endl;
        return front->data;
    }
    bool isEmpty()
    {
        if (front == NULL)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.deQueue();
    q.peek();
    return 0;
}