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

Node *solve(int &i, int pre[], int size, int bound)
{
    if (i >= size || pre[i] >= bound)
        return NULL;
    Node *root = new Node(pre[i++]);

    root->left = solve(i, pre, size, root->data);
    root->right = solve(i, pre, size, bound);

    return root;
}
Node *post_order(int pre[], int size)
{
    int i = 0;
    return solve(i, pre, size, INT_MAX);
}

int main()
{

    return 0;
}