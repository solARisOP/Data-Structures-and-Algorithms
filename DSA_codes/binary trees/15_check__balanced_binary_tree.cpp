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

    int lh = height_tree(root->left);
    if(lh == -1) return -1;

    int rh = height_tree(root->right);
    if(rh == -1) return -1;

    if(abs(lh - rh) > 1) return -1;

    return max(lh, rh) +1;
}

bool check_balance(Node *root)
{
    return height_tree(root) != -1; 
}

int main()
{
    
    return 0;
}