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

int solve(Node *node)
{
    if (!node)
        return 0;
    if (!node->left && !node->right)
        return node->data;

    int temp = node->data;
    int l = solve(node->left);
    int r = solve(node->right);

    if (l == -1 || r == -1)
        return -1;

    if (temp == l + r)
        return 2 * temp;
    return -1;
}
bool isSumTree(Node *root)
{
    // Your code here
    if (solve(root) == -1)
        return 0;
    return 1;
}

int main()
{

    return 0;
}