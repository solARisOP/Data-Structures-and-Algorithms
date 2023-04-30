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

vector<int> in;
void inorder(Node *root)
{
    if (!root)
        return;

    inorder(root->left);
    in.push_back(root->data);
    inorder(root->right);
}
Node *build_tree(int i, int j)
{
    if (i > j)
        return NULL;
    int ind = i + (j - i) / 2;
    Node *root = new Node(in[ind]);

    root->left = build_tree(i, ind - 1);
    root->right = build_tree(ind + 1, j);

    return root;
}
Node *balanceBST(Node *root)
{
    inorder(root);
    return build_tree(0, in.size() - 1);
}

int main()
{

    return 0;
}