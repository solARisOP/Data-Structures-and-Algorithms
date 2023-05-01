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

class Nodeval
{
public:
    int small, large, size;
    Nodeval(int s, int l, int x) : small(s), large(l), size(x) {}
};

Nodeval solve(Node *root)
{
    if (!root) return Nodeval(INT_MAX, INT_MIN, 0);

    auto l = solve(root->left);
    auto r = solve(root->right);

    if (l.large < root->data && root->data < r.small)
    {
        return Nodeval(min(root->data, l.small), max(root->data, r.large), 1 + l.size + r.size);
    }
    else
    {
        return Nodeval(INT_MIN, INT_MAX, max(l.size, r.size));
    }
}
int largestBst(Node *root)
{
    return solve(root).size;
}

int main()
{

    return 0;
}