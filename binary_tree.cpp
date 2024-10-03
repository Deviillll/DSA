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
// in order traversal
void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
// pre order traversal
void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
// post order traversal
void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// count nodes in binary tree
int countNodes(Node *root)
{
    return root ? 1 + countNodes(root->left) + countNodes(root->right) : 0;
}

int main()
{

    Node *root = binaryTree();
    cout << "In-order Traversal: ";
    inOrder(root);
    cout << endl;

    cout << "Pre-order Traversal: ";
    preOrder(root);
    cout << endl;

    cout << "Post-order Traversal: ";
    postOrder(root);
    cout << endl;
    int totalNodes = countNodes(root);
    cout << "Total number of nodes: " << totalNodes << endl;

    return 0;
}