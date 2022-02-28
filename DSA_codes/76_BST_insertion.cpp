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

void insert(node *root, int key)
{
    node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data == key)
        {
            cout << key << " already exist, cannot create a new node for it in the BST" << endl;
            return;
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
    node *n = createnode(key);
    if (n->data < prev->data)
    {
        prev->left = n;
    }
    else
    {
        prev->right = n;
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

    insert(p, 5);
    cout << p->left->right->left->data;

    return 0;
}