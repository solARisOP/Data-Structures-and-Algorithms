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

void solve(Node *root, Node *&prev, bool &ans)
{
    if (!ans || !root)
        return;
    solve(root->left, prev, ans);
    if (!prev)
        prev = root;
    else
    {
        if (prev->val >= root->val)
        {
            ans = false;
            return;
        }
        prev = root;
    }
    solve(root->right, prev, ans);
}

bool isValidBST(Node *root)
{
    Node *prev = NULL;
    bool ans = true;
    solve(root, prev, ans);
    return ans;
}

int main()
{

    return 0;
}