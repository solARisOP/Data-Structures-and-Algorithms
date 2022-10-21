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

void preorder(Node * root)
{
    if(!root) return;

    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    
    return 0;
}