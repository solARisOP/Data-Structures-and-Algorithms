#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

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

Node *solve(Node *root, Node *p, Node *q)
{
    if (!root || root == p || root == q) return root;

    Node *l = solve(root->left, p, q);
    Node *r = solve(root->right, p, q);

    if (l && r) return root;
    return l ? l : r;
}
Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    return solve(root, p, q);
}

int main()
{
    
    return 0;
}