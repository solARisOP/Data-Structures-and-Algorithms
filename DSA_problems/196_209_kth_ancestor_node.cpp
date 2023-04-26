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

int solve(Node * root, int k, int x, int &ans)
{
    if(!root || ans != -1) return 0;
    
    if(root->data == x) return 1;
    
    int l = solve(root->left, k, x, ans);
    int r = solve(root->right, k, x, ans);
    
    if(l == k || r == k && ans == -1) ans = root->data;
    if(l) return l+1;
    else if(r) return r+1;
    else return 0;
    
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    int ans = -1;
    solve(root, k, node, ans);
    return ans;
}

int main()
{
    
    return 0;
}