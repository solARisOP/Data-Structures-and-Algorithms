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

int solve(Node *root, int &ans)
{
    if (!root)
        return 0;

    int l = max(0, solve(root->left, ans));
    int r = max(0, solve(root->right, ans));

    ans = max(ans, root->val + l + r);
    return root->val + max(l, r);
}

int maxPathSum(Node *root)
{
    int ans = INT_MIN;
    solve(root, ans);
    return ans;
}

int main()
{

    return 0;
}