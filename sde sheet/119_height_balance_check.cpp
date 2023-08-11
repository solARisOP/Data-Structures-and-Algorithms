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

int solve(Node *root, bool &ans)
{
    if (!root || !ans) return 0;

    int l = solve(root->left, ans);
    int r = solve(root->right, ans);
    
    if (abs(l - r) > 1) ans = false;
    return 1 + max(l, r);
}
bool isBalanced(Node *root)
{
    bool ans = true;
    solve(root, ans);
    return ans;
}

int main()
{

    return 0;
}