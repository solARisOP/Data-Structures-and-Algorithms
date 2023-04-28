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

bool chk = 1;
int fl = 0, ele = 0;
void solve(Node *root)
{
    if (!root || !chk)
        return;
    solve(root->left);
    if (fl == 0)
    {
        ele = root->data;
        fl = 1;
    }
    else if (ele >= root->data)
    {
        chk = 0;
        return;
    }
    else
        ele = root->data;
    solve(root->right);
}

bool isValidBST(Node *root)
{
    solve(root);
    return chk;
}
int main()
{

    return 0;
}