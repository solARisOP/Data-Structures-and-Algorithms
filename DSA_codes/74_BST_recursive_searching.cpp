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

node *search(node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        if (root->data == key)
        {
            return root;
        }
        else if (root->data > key)
        {
            return search(root->left, key);
        }
        else
        {
            return search(root->right, key);
        }
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

    node *n = search(p, 6);

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