#include <iostream>
using namespace std;
class MaxHeap
{
    int *arr;
    int size;
    int capacity;

public:
    MaxHeap(int c)
    {
        arr = new int[c];
        size = 0;
        capacity = c;
    }

    void insert(int val)
    {
        if (size == capacity)
            return;

        arr[size++] = val;
        for (int i = size - 1; i != 0 && arr[(i - 1) / 2] < arr[i];)
        {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
    void print()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};
// insert into heap

int main()
{
    MaxHeap h(10);
    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.insert(40);
    h.insert(50);
    h.insert(100);
    h.print();

    return 0;
}