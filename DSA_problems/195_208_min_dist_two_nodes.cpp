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

int solve(Node *root, int a, int b, int &ans)
{
    if (!root || ans)return 0;

    int l = solve(root->left, a, b, ans);
    int r = solve(root->right, a, b, ans);

    if ((root->data == a || root->data == b))
    {
        if (l != 0) ans = l;
        else if (r != 0) ans = r;
        else return 1;
    }

    if (l && r && !ans) ans = l + r;
    if (l) return 1 + l;
    else if (r) return 1 + r;
    else return 0;
}

int findDist(Node *root, int a, int b)
{
    // Your code here
    int ans = 0;
    solve(root, a, b, ans);
    return ans;
}

int main()
{

    return 0;
}