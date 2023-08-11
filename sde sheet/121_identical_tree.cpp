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

bool solve(Node *p, Node *q)
{
    if (!p || !q) return p == q;
    if (p->val != q->val) return false;

    return solve(p->left, q->left) && solve(p->right, q->right);
}

bool isSameTree(Node *p, Node *q)
{
    return solve(p, q);
}

int main()
{

    return 0;
}