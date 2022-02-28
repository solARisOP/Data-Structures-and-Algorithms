#include <iostream>
using namespace std;

class node
{
public:
    node *left;
    node *right;
    int data;
};

node *createnode(int val)
{
    node *n = new node();
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int get_height(node *n)
{
    if (n == NULL)
    {
        return -1;
    }
    else
    {
        int lheight = get_height(n->left);
        int rheight = get_height(n->right);

        if (lheight > rheight)
        {
            return lheight + 1;
        }
        else
        {
            return rheight + 1;
        }
    }
}

int balance_factor(node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return get_height(n->left) - get_height(n->right);
}

node *rightrotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;

    x->right = y;
    y->left = T2;

    return x;
}

node *leftrotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
}

node *insertnode(node *r, int key)
{
    if (r == NULL)
    {
        return createnode(key);
    }
    if (key > r->data)
    {
        r->right = insertnode(r->right, key);
    }
    else if (key < r->data)
    {
        r->left = insertnode(r->left, key);
    }

    int bf = balance_factor(r);

    // left - left rotation
    if (bf > 1 && key < r->left->data)
    {
        return rightrotate(r);
    }

    // right - right rotation
    if (bf < -1 && key > r->right->data)
    {
        return leftrotate(r);
    }

    // left - right rotation
    if (bf > 1 && key > r->left->data)
    {
        r->left = leftrotate(r->left);
        return rightrotate(r);
    }

    // right - left rotation
    if (bf < -1 && key < r->right->data)
    {
        r->right = rightrotate(r->right);
        return leftrotate(r);
    }
    return r;
}

void preorder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << "  ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    node *r = NULL;
    r = insertnode(r, 1);
    r = insertnode(r, 2);
    r = insertnode(r, 4);
    r = insertnode(r, 5);
    r = insertnode(r, 6);
    r = insertnode(r, 3);

    preorder(r);

    return 0;
}