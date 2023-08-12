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

// recurssive
Node *previ = NULL;
void solve(Node *root)
{
    if (!root) return;

    solve(root->right);
    solve(root->left);

    root->right = previ;
    root->left = NULL;
    previ = root;
}

void flatten(Node *root)
{
    solve(root);
}

// iterative
void flatten(Node *root)
{
    while (root)
    {
        if (root->left)
        {
            Node *curr = root->left;
            while (curr->right) curr = curr->right;
            curr->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        root = root->right;
    }
}

int main()
{

    return 0;
}