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

class Nodeval
{
public:
    int mini, maxi, sum;
    Nodeval(int mi, int ma, int s) : mini(mi), maxi(ma), sum(s) {}
};

Nodeval solve(Node *root, int &ans)
{
    if (!root)
        return Nodeval(INT_MAX, INT_MIN, 0);
    Nodeval l = solve(root->left, ans);
    Nodeval r = solve(root->right, ans);
    if (root->val > l.maxi && root->val < r.mini)
    {
        int sum = root->val + l.sum + r.sum;
        ans = max(ans, sum);
        return Nodeval(min(l.mini, root->val), max(r.maxi, root->val), sum);
    }
    return Nodeval(INT_MIN, INT_MAX, 0);
}

int maxSumBST(Node *root)
{
    int ans = 0;
    solve(root, ans);
    return ans;
}

int main()
{
    
    return 0;
}