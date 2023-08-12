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

bool solve(Node *a, Node *b)
{
    if (!a || !b)
        return a == b;
    if (a->val != b->val)
        return false;

    return solve(a->left, b->right) && solve(a->right, b->left);
}
bool isSymmetric(Node *root)
{
    return solve(root->left, root->right);
}

int main()
{

    return 0;
}