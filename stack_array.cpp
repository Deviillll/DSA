#include <iostream>
using namespace std;
const int SIZE = 5;

class Stack
{
    int top;
    int arr[SIZE];

public:
    Stack()
    {
        top = -1;
    }
    void push(int val)
    {
        if (top >= SIZE - 1)
        {
            cout << "stack overflow" << endl;
        }
        else
        {
            arr[++top] = val;
            cout << val << " is pushed into the stack and index is " << top + 1 << endl;
        }
    }
    void pop()
    {
        if (top < 0)
        {
            cout << "stack underflow" << endl;
        }
        else
        {
            cout << arr[top] << " is popped from the stack and";
            top--;
            cout << " index is " << top + 1 << endl;
        }
    }
    int peek()
    {
        if (top < 0)
        {
            cout << "stack is empty" << endl;
            return 0;
        }
        else
        {
            cout << arr[top] << " is the top element of the stack" << endl;
            return arr[top];
        }
    }
    bool isEmpty()
    {
        return top < 0;
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    s.peek();
    bool check = s.isEmpty();
    cout << check << endl;
    return 0;
}