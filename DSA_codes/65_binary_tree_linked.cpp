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

int main()
{
    // creating the nodes
    node *p, *p1, *p2;
    p = createnode(7);
    p1 = createnode(34);
    p2 = createnode(16);

    // connecting the nodes
    p->left = p1;
    p->right = p2;
    
    return 0;
}