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

Node *solve(Node *root, int fl)
{
    if (!root) return NULL;

    Node *l = solve(root->left, 0);
    Node *r = solve(root->right, 1);

    root->left = l;
    if(l) l->right = root;
    else l = root;

    root->right = r;
    if(r) r->left = root;
    else r = root;

    if(!fl)
    {
        while(r->right) r = r->right;
        return r;
    }
    else if(fl)
    {
        while (l->left) l = l->left;
        return l;
    }
}

Node *bToDLL(Node *root)
{
    // your code here
    root = solve(root, 1);
    return root;
}
int main()
{

    return 0;
}