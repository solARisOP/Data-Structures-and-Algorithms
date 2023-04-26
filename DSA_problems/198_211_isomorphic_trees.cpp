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

bool solve(Node *a, Node *b)
{
    if (!a || !b) return a == b;

    if (a->data != b->data) return false;

    return (solve(a->left, b->left) && solve(a->right, b->right)) || 
           (solve(a->left, b->right) && solve(a->right, b->left));
}
bool isIsomorphic(Node *root1, Node *root2)
{
    // add code here.
    return solve(root1, root2);
}

int main()
{

    return 0;
}