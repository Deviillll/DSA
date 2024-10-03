#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *insert(Node *root, int data)
{
    Node *newNode = new Node(data);
    if (root == NULL)
    {
        return newNode;
    }
    Node *current = root;
    Node *parent = NULL;
    while (current != NULL)
    {
        parent = current;
        if (data < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    if (data < parent->data)
    {
        parent->left = newNode;
    }
    else
    {
        parent->right = newNode;
    }
    return root;
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main()
{
    Node *root = NULL;
    int values[] = {10, 9, 8, 7, 6, 5, 4};
    for (int value : values)
    {
        root = insert(root, value);
    }

    cout << "In-order Traversal of BST: ";
    inOrder(root);
    cout << endl;

    return 0;
}
