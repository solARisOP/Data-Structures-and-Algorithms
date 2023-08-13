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

Node *solve(vi &pre, int &i, int bound)
{
    if (i >= pre.size() || pre[i] > bound)
        return NULL;
    Node *root = new Node(pre[i++]);
    root->left = solve(pre, i, root->val);
    root->right = solve(pre, i, bound);
    return root;
}
Node *bstFromPreorder(vector<int> &preorder)
{
    int i = 0;
    return solve(preorder, i, INT_MAX);
}

int main()
{

    return 0;
}