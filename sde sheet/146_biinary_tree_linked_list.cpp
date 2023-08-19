#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

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

// solving via reverse inorder
void solve(Node* root, Node* &last)
{
    if(!root) return;

    solve(root->right, last);

    root->right = last;
    if(last) last->left = root;
    last = root;
    
    solve(root->left, last);
}
Node* BTtoDLL(Node* root) {
    // Write your code here
    Node* last = NULL;
    solve(root, last);
    return last;
}

// solving via inorder
void solve(Node* root, Node* &last)
{
    if(!root) return;

    solve(root->left, last);

    root->left = last;
    last->right = root;
    last = root;
    
    solve(root->right, last);
}
Node* BTtoDLL(Node* root) {
    // Write your code here
    Node* dummy = new Node(-1);
    Node* last = new Node(-1);
    last->left = dummy;
    dummy->right = last;
    solve(root, last);
    root = (dummy->right)->right;
    root->left = NULL;
    return root;
}

int main()
{
    
    return 0;
}