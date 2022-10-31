#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

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

bool same_tree(Node * a, Node * b)
{
    if(!a || !b) return (a == b);

    return (a->val == b->val) && same_tree(a->left, b->left) && same_tree(a->right, b->right);
}


int main()
{

    return 0;
}