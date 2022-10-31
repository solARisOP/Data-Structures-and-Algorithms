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

Node * solve(Node * root, Node * a, Node * b)
{
    if(!root || root == a || root == b) return root; // if the root is NULL or it mathes with any of the two nodes we return it

    Node * x = solve(root->left, a, b); 
    Node * y = solve(root->right, a, b);

    if(x && y) return root; // if they both are not NULL it means we have got our lca so we return the root which is the lca
    return (!x) ? y : x;  // or else if any one of them are NULL we return the other root if the other is also NULL it is ok we return it
}

Node * lca(Node * root, Node * a, Node * b)
{
    return solve(root, a, b);
}

int main()
{

    return 0;
}