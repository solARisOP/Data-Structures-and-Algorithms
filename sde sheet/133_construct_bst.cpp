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

Node *solve(int i, int j, vi &nums)
{
    if (i > j)
        return NULL;
    int ind = i + (j - i) / 2;
    int x = nums[ind];
    Node *root = new Node(x);
    root->left = solve(i, ind - 1, nums);
    root->right = solve(ind + 1, j, nums);
    return root;
}

Node *sortedArrayToBST(vector<int> &nums)
{
    int n = nums.size();
    return solve(0, n - 1, nums);
}

int main()
{

    return 0;
}