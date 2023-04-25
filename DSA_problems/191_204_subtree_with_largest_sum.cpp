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

int solve(Node * root, int &maxi)
{
    if(!root) return 0;

    int l = solve(root->left, maxi); 
    int r = solve(root->right, maxi); 

    maxi = max(maxi, root->data + l + r);

    return root->data + l + r;    
}
int findLargestSubtreeSum(Node* root)
{
    int maxi = INT_MIN;
    solve(root, maxi);
    return maxi;
}
int main()
{
    
    return 0;
}