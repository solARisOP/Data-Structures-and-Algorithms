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

void solve(Node * root)
{
    if(!root) return;

    int sum = 0;
    if(root->left) sum+=root->left->val;
    if(root->right) sum+=root->right->val;
    
    // after getting the sum for above
    if(sum >= root->val) root->val = sum; // we are checking if the sum is greater then we assign it to the root
    else // or else if it is less then we assign the root->val to the children
    {
        if(root->left) root->left->val = root->val;
        if(root->right) root->right->val = root->val;
    }

    solve(root->left);
    solve(root->right);

    int total = 0, flag = 0;

    if(root->left)
    {
        total += root->left->val;
        flag =1;
    }
    if(root->right)
    {
        total += root->right->val;
        flag = 1;
    } 
    if(flag) root->val = total; // after backtracking from the calls we do the children sum and assign it to the root (this is children sum property)
    
}

void sum_property(Node * root)
{
    solve(root);
}

int main()
{
    
    return 0;
}