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
    if (head == nullptr)
        return;
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
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
            p->next = head;
        }
        else
        {
            q->next = p;
            p->next = head;
        }
        q = p;
    }

    // insert node at first
    p = head;
    while (p->next != head)
    {

        p = p->next;
    }
    Node *temp = new Node(10);
    temp->next = head;
    head = temp;
    p->next = head;
    // insert node at last
    Node *last = new Node(20);
    Node *l = head;
    while (l->next != head)
    {
        l = l->next;
    }
    l->next = last;
    last->next = head;
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
    p, q = head;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = head->next;
    head = head->next;
    delete q;
    // delete node at last
    p = head;
    while (p->next->next != head)
    {
        p = p->next;
    }
    delete p->next;
    p->next = head;
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