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

Node *solve(Node *root, int n1, int n2)
{
    if (!root || root->data == n1 || root->data == n2) return root;

    Node *l = solve(root->left, n1, n2);
    Node *r = solve(root->right, n1, n2);

    if (l && r) return root;
    return l ? l : r;
}
Node *lca(Node *root, int n1, int n2)
{
    // Your code here
    return solve(root, n1, n2);
}

int main()
{

    return 0;
}