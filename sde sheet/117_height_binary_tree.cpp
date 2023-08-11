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

int solve(Node *root)
{
    if (!root)
        return 0;

    int l = solve(root->left);
    int r = solve(root->right);

    return 1 + max(l, r);
}

int maxDepth(Node *root)
{
    return solve(root);
}

int main()
{

    return 0;
}