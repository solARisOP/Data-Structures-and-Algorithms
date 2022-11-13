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

void preorder_recursive(Node * root, vi &pre)
{
    if(!root) return;

    pre.push_back(root->val);
    preorder_recursive(root->left, pre);
    preorder_recursive(root->right, pre);
}

void preorder_iterative(Node * root)
{
    stack<Node*> st;
    vi pre;
    st.push(root);

    while(!st.empty())
    {
        Node * curr = st.top();
        st.pop();
        pre.push_back(curr->val);

        if(curr->right) st.push(curr->right);
        if(curr->left) st.push(curr->left);
    }
}

int main()
{
    
    return 0;
}