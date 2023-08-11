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

void left_border(Node * root, vi &res)
{
    root = root->left;

    while(root)
    {
        if(root->left || root->right)res.push_back(root->val);
        if(root->left) root = root->left;
        else root = root->right;
    }
}

void right_border(Node * root, vi &res)
{
    root = root->right;
    stack<Node *> st;
    while(root)
    {
        if(root->left || root->right )st.push(root);
        if(root->right) root = root->right;
        else root = root->left;
    }

    while(!st.empty())
    {
        res.push_back(st.top()->val);
        st.pop();
    }
}

void leaf_traverse(Node * root, vi &res)
{
    if(!root) return;
    if(!root->left && !root->right) res.push_back(root->val);
    leaf_traverse(root->left, res);
    leaf_traverse(root->right, res);
}

vector<int> traverseBoundary(Node* root){
    // Write your code here.
    vector<int> ans;
    if(!root) return ans;
    if(root->left || root->right)ans.push_back(root->val);
    left_border(root, ans);
    leaf_traverse(root, ans);
    right_border(root, ans);
    return ans;
}

int main()
{
    
    return 0;
}