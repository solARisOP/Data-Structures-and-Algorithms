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

Node *solve(vi &pre, int &i, int bound)
{
    if (i >= pre.size() || pre[i] >= bound)
        return NULL;

    Node *root = new Node(pre[i++]);

    root->left = solve(pre, i, root->data);
    root->right = solve(pre, i, bound);

    return root;
}
Node *bstFromPreorder(vi &preorder)
{
    int i = 0;
    return solve(preorder, i, INT_MAX);
}

int main()
{

    return 0;
}