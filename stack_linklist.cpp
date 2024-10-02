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
class Stack
{
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }
    void push(int val)
    {
        Node *n = new Node(val);
        n->next = top;
        top = n;
        cout << val << " is pushed into the stack" << endl;
    }
    void pop()
    {
        if (top == NULL)
        {
            cout << "stack underflow" << endl;
            return;
        }
        Node *toDelete = top;
        top = top->next;
        cout << toDelete->data << " is popped from the stack" << endl;
        delete toDelete;
    }
    int peek()
    {
        if (top == NULL)
        {
            cout << "stack is empty" << endl;
            return -1;
        }
        cout << top->data << " is the top element of the stack" << endl;
        return top->data;
    }
    bool isEmpty()
    {
        return top == NULL;
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.pop();

    return 0;
}