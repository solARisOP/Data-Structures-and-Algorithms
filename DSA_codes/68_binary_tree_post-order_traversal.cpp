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

void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << "  ";        
    }
}

int main()
{
    node *p, *p1, *p2, *p3, *p4;
    p = createnode(7);
    p1 = createnode(23);
    p2 = createnode(19);
    p3 = createnode(1);
    p4 = createnode(17);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    postorder(p);

    return 0;
}