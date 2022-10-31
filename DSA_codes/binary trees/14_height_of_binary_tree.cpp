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

int height_tree(Node *root)
{
    if(!root) return 0;
    return 1 + max(height_tree(root->left), height_tree(root->right));
}

int main()
{
    
    return 0;
}