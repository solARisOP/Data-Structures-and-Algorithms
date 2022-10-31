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

int height(Node * root, int &sum)
{
    if(!root) return 0;

    int lh = max(0, height(root->left, sum)); // if a node has -ve val we are not considering it coz it will mess up the path sum of the paths above this node
    int rh = max(0, height(root->right, sum));

    sum = max(sum, root->val + lh + rh); // we are keeping track of the max sum path

    return  root->val + max(lh, rh); // we are returning the max path for further calculations  
}

int max_path(Node * root)
{
    int sum = INT_MIN;
    height(root, sum);
    return sum;
}
int main()
{
    
    return 0;
}