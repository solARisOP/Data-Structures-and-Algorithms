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

void inorder_recursive(Node * root, vi &in)
{
    if(!root) return ;

    inorder_recursive(root->left, in);
    in.push_back(root->val);
    inorder_recursive(root->right, in);
}

vi inorder_iterative(Node* root)
{
    Node * curr = root;
    stack<Node *> st;
    vi in;

    while(1)
    {
        if(curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            if(st.empty()) break;
            Node * temp = st.top();
            st.pop();
            in.push_back(temp->val);
            temp = temp->right;
        }
    }

    return in;
}

int main()
{
    
    return 0;
}