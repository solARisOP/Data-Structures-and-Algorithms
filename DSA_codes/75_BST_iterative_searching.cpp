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

node *searchitr(node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
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

    node *n = searchitr(p, 7);

    if (n != NULL)
    {
        cout << "Found : " << n->data << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    return 0;
}