#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

class Node
{
    public:
        int data;
        Node *left;
        Node *right;

        Node() : data(0), left(NULL), right(NULL) {}
        Node(int x) : data(x), left(NULL), right(NULL) {}
        Node(int x, Node *a, Node *b) : data(x), left(a), right(b) {}
};

void inorder(Node* root, Node*& prev)
{
    if (root == NULL)
        return;
    inorder(root->left, prev);
    prev->left = NULL;
    prev->right = root;
    prev = root;
    inorder(root->right, prev);
}
 

Node* flatten(Node* root)
{

    Node* dummy = new Node(-1);

    Node* prev = dummy;

    inorder(root, prev);
 
    prev->left = NULL;
    prev->right = NULL;
    Node* ret = dummy->right;

    delete (dummy);
    return ret;
}

int main()
{
    
    return 0;
}