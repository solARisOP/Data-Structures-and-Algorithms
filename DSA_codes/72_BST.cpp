#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
};

node *createnode(int val)
{
    node *n = new node();
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << "  ";
        inorder(root->right);
    }
}

int isBST(node *root)
{
    static node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

int main()
{
    node *p, *p1, *p2, *p3, *p4;
    p = createnode(7);
    p1 = createnode(2);
    p2 = createnode(19);
    p3 = createnode(1);
    p4 = createnode(6);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    inorder(p);
    cout << endl;
    if (isBST(p))
    {
        cout << "It is a BST" << endl;
    }
    else
    {
        cout << "Not a BST" << endl;
    }

    return 0;
}