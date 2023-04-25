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

int solve(Node *a, Node *b, bool &exist)
{
    if (!a && !b)
        return 0;

    if (!a || !b)
        return -1;

    if ((a->data == b->data) && (!a->left && !a->right) && (!b->left && !b->right))
        return 1;

    if (a->data == b->data)
    {
        int l = solve(a->left, b->left, exist);
        int r = solve(a->right, b->right, exist);

        if (l != -1 && r != -1)
        {
            exist = 1;
            return 1 + (r + l);
        }
        else
            return -1;
    }
    else
    {
        int sa = solve(a, b->left, exist);
        int sa_ = solve(a, b->right, exist);

        int sb = solve(a->left, b, exist);
        int sb_ = solve(a->right, b, exist);

        if (sa > 1 || sb > 1 || sa_ > 1 || sb_ > 1)
            exist = 1;

        return -1;
    }
}

int dupSub(Node *root)
{
    // code here
    bool exist = 0;
    solve(root->left, root->right, exist);
    return exist;
}

int main()
{

    return 0;
}