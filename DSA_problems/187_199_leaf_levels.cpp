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

int solve(Node *root, bool &check)
{
    if (!root) return -1;
    if (!root->left && !root->right) return 1;

    int l = solve(root->left, check);
    int r = solve(root->right, check);

    if (l != -1 && r != -1 && l != r) check = 0;

    if (l == -1 && r != -1) return 1 + r;
    return 1 + l;
}

bool check(Node *root)
{
    // Your code here
    bool check = 1;
    solve(root, check);
    return check;
}

int main()
{

    return 0;
}