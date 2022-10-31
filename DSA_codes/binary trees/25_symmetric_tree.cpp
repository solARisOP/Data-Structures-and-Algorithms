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

bool symmetric_check(Node * left, Node * right)
{
    if(!left || !right) return left == right;

    if(left->val != right->val) return false;

    return symmetric_check(left->left, right->right) && symmetric_check(left->right, right->left);
}

bool symmetric_tree(Node * root)
{
    return root == NULL || symmetric_check(root->left, root->right);
}

int main()
{
    
    return 0;
}