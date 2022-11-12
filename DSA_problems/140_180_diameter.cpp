#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

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

int maxi = 0;
int solve(Node *root)
{
    if (!root) return 0;

    int lh = solve(root->left);
    int rh = solve(root->right);

    maxi = max(maxi, 1 + lh + rh);

    return max(1 + lh, 1 + rh);
}

int diameter(Node *root)
{
    solve(root);
    return maxi;
}

int main()
{

    return 0;
}