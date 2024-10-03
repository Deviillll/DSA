#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node *binaryTree()
{
    int x;
    cin >> x;
    if (x == -1)
    {
        return NULL;
    }
    Node *root = new Node(x);
    cout << "Enter left child of " << x << " : ";
    root->left = binaryTree();
    cout << "Enter right child of " << x << " : ";
    root->right = binaryTree();
    return root;
}

int main()
{

    Node *root = binaryTree();
    return 0;
}