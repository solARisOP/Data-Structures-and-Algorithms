#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node() : val(0), left(NULL), right(NULL) {}
    Node(int x) : val(x), left(NULL), right(NULL) {}
    Node(int x, Node *a, Node *b) : val(x), left(a), right(b) {}
};

Node * mirror(Node * root)
{
    if(!root) return NULL;

    Node * temp = new Node(root->val);

    temp->left = mirror(root->right);
    temp->right = mirror(root->left);

    return temp;
}

void inorder(Node* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int main()
{
    Node* tree = new Node(5);
    tree->left = new Node(3);
    tree->right = new Node(6);
    tree->left->left = new Node(2);
    tree->left->right = new Node(4);

    inorder(tree);
    cout<<endl;

    tree = mirror(tree);

    inorder(tree);
    
    return 0;
}