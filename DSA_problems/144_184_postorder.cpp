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

void postorder_recursive(Node * root, vi &post)
{
    if(!root) return;

    postorder_recursive(root->left, post);
    postorder_recursive(root->right, post);
    post.push_back(root->val);
}

vi postorder_iterative(Node * root)
{
    stack<Node*> st, ot;

    st.push(root);
    vi post;

    while(!st.empty())
    {
        Node * curr = st.top();
        st.pop();

        if(curr->left) st.push(curr->left);
        if(curr->right) st.push(curr->right);

        ot.push(curr);
    }

    while(!ot.empty())
    {
        post.push_back(ot.top()->val);
        ot.pop();
    }

    return post;
}

int main()
{
    
    return 0;
}