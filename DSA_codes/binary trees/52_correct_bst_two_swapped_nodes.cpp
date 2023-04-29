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

Node *x, *y, *previ;
void solve(Node *root)
{
    if (!root)
        return;
    solve(root->left);
    if (previ && previ->data > root->data)
    {
        if (!x)
        {
            x = previ;
            y = root;
        }
        else
            y = root;
    }
    previ = root;
    solve(root->right);
}
void recoverTree(Node *root)
{
    x = y = previ = NULL;
    solve(root);
    swap(x->data, y->data);
}

int main()
{

    return 0;
}