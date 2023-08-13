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

// recursive
Node *solve(Node *root, Node *p, Node *q)
{
    if (p->val <= root->val && root->val <= q->val)
        return root;

    if (root->val < p->val)
        return solve(root->right, p, q);
    else
        return solve(root->left, p, q);
}
Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    if (p->val > q->val)
    {
        Node *temp = p;
        p = q;
        q = temp;
    }
    return solve(root, p, q);
}

// iterative
Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    if (p->val > q->val)
    {
        Node *temp = p;
        p = q;
        q = temp;
    }
    while (1)
    {
        if (p->val <= root->val && root->val <= q->val)
            return root;
        root = (root->val < p->val) ? root->right : root->left;
    }
    return NULL;
}

int main()
{

    return 0;
}