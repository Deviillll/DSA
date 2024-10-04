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
    // delete from heap
    void deleteMax()
    {
        if (size <= 0)
            return; // If heap is empty, do nothing

        arr[0] = arr[--size]; // Move the last element to the root and decrease size
        heapify(0);           // Restore the heap property
    }

    void heapify(int i)
    {
        int largest = i;       // Initialize largest as root
        int left = 2 * i + 1;  // left child
        int right = 2 * i + 2; // right child

        // If left child is larger than root
        if (left < size && arr[left] > arr[largest])
            largest = left;

        // If right child is larger than largest so far
        if (right < size && arr[right] > arr[largest])
            largest = right;

        // If largest is not root
        if (largest != i)
        {
            swap(arr[i], arr[largest]); // Swap root with largest
            heapify(largest);           // Recursively heapify the affected sub-tree
        }
    }

    void print()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

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
    h.deleteMax();
    h.print();

    return 0;
}