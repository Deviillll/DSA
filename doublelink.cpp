#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
        prev = nullptr;
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
            p->prev = q;
        }
        q = p;
    }

    // insert node at first
    Node *temp = new Node(10);
    p = head;
    temp->next = head;
    p->prev = temp;
    head = temp;
    //
    // insert node at last
    Node *last = new Node(20);
    Node *l = head;
    while (l->next != nullptr)
    {
        l = l->next;
    }
    l->next = last;
    last->prev = l;
    // insert node at 3 index position
    Node *random = new Node(100);
    Node *r = head;
    for (int i = 1; i < 2; i++)
    {
        r = r->next;
    }
    random->next = r->next;
    r->next->prev = random;
    r->next = random;
    random->prev = r;
    // delelte node at 1
    Node *d = head;
    head = head->next;
    head->prev = nullptr;
    delete d;
    // delete node at last
    Node *d1 = head;
    while (d1->next->next != nullptr)
    {
        d1 = d1->next;
    }
    delete d1->next;
    d1->next = nullptr;
    // delete node at 3 index position

    p = head;
    for (int i = 1; i < 4; i++)
    {
        p = p->next;
    }

    p->prev->next = p->next;

    p->next->prev = p->prev;
    delete p;

    printList(head);

    return 0;
}