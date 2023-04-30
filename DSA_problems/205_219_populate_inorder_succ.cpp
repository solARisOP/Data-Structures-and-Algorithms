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
        Node *next;

        Node() : data(0), left(NULL), right(NULL) {}
        Node(int x) : data(x), left(NULL), right(NULL) {}
        Node(int x, Node *a, Node *b) : data(x), left(a), right(b) {}
};

Node *previ = NULL;
void solve(Node *root)
{
    if (!root)
        return;

    solve(root->left);
    if (previ)
        previ->next = root;
    previ = root;
    solve(root->right);
}
void populateNext(Node *root)
{
    // code here
    solve(root);
}

int main()
{

    return 0;
}