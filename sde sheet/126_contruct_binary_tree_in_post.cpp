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

Node *solve(int ind, int strt, int end, vi &post, vi &in, unordered_map<int, int> &mpp)
{
    if (strt > end)
        return NULL;
    Node *root = new Node(post[ind]);
    int idx = mpp[post[ind]];
    root->left = solve(ind - (end - idx + 1), strt, idx - 1, post, in, mpp);
    root->right = solve(ind - 1, idx + 1, end, post, in, mpp);

    return root;
}

Node *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    unordered_map<int, int> mpp;
    int n = inorder.size();
    for (int i = 0; i < n; i++)
    {
        mpp[inorder[i]] = i;
    }

    return solve(n - 1, 0, n - 1, postorder, inorder, mpp);
}

int main()
{

    return 0;
}