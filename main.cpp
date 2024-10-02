#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = nullptr, *p, *q = nullptr;

    for (int i = 0; i < 5; i++)
    {
        p = new Node(i);
        if (head == nullptr)
        {
            head = p;
        }
        else
        {
            q->next = p;
        }
        q = p;
    }
    // insert node at first
    Node *temp = new Node(10);
    temp->next = head;
    head = temp;
    // insert node at last
    Node *last = new Node(20);
    Node *l = head;
    while (l->next != nullptr)
    {
        l = l->next;
    }

    l->next = last;
    // insert node at 3 index position
    Node *random = new Node(100);
    Node *r = head;
    for (int i = 1; i < 2; i++)
    {
        r = r->next;
    }
    random->next = r->next;

    r->next = random;

    // delete node at first
    p = head;
    head = head->next;
    delete p;
    // delete node at last
    p = head;
    while (p->next->next != nullptr)
    {
        p = p->next;
    }
    delete p->next;
    p->next = nullptr;
    // delete node at 3 index position
    p = head;
    for (int i = 1; i < 2; i++)
    {
        p = p->next;
    }
    q = p->next;
    p->next = q->next;
    delete q;

    printList(head);

    return 0;
}
