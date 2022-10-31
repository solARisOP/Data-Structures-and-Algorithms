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

int height(Node *root, int &diameter)
{
    if(!root) return 0;

    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);

    diameter = max(diameter, lh+rh);

    return 1 + max(lh, rh);
}

int diameter_binary(Node * root)
{
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int main()
{
    
    return 0;
}