#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

class Node
{
    public:
        int data;
        Node *left;
        Node *right;

        Node() : data(0), left(NULL), right(NULL) {}
        Node(int x) : data(x), left(NULL), right(NULL) {}
        Node(int x, Node *a, Node *b) : data(x), left(a), right(b) {}
};

int solve(Node *root, unordered_map<Node *, int> &dp)
{
    if (!root) return 0;
    if (dp.find(root) != dp.end()) return dp[root];

    int pick = root->data, n_pick = 0;
    if (root->left)
    {
        pick += solve(root->left->left, dp);
        pick += solve(root->left->right, dp);
    }
    if (root->right)
    {
        pick += solve(root->right->left, dp);
        pick += solve(root->right->right, dp);
    }

    n_pick += solve(root->left, dp);
    n_pick += solve(root->right, dp);

    return dp[root] = max(pick, n_pick);
}
int getMaxSum(Node *root)
{
    // Add your code here
    unordered_map<Node *, int> dp;
    return solve(root, dp);
}

int main()
{

    return 0;
}