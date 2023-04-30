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

bool validate(Node *root, int mini, int maxi)
{
    if (!root) return true;
    if (mini >= root->data || root->data >= maxi) return false;

    return validate(root->left, mini, root->data) && validate(root->right, root->data, maxi);
}

bool isBST(Node *root)
{
    // Your code here
    return validate(root, INT_MIN, INT_MAX);
}

int main()
{

    return 0;
}