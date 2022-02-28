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

node *predecessor(node *root, int key)
{
    root = root->left;
    while(root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

node * deletion(node *root, int key)
{
    node *ipre;
    if(root == NULL)
    {
        return NULL;
    }
    if(root->left == NULL && root->right == NULL)
    {
        delete (root);
        return NULL;
    }
    
    
    if(key<root->data)
    {
        root->left =  deletion(root->left, key);
    }
    else if(key>root->data)
    {
        root->right =  deletion(root->right, key);
    }
    else
    {
        ipre = predecessor(root, key);
        root->data = ipre->data;
        root->left = deletion(root->left, ipre->data);
    }
    return root;

    
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
    cout<<endl;
    deletion(p, 7);
    inorder(p);


    return 0;
}