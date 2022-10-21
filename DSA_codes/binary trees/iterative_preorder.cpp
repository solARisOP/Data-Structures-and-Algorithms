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

vi iter_preorder(Node * root)
{
    vi ans;

    if(!root) return ans;
    stack<Node*> st;
    
    st.push(root);
    while(!st.empty())
    {
        Node * temp = st.top();
        st.pop();
        ans.push_back(temp->val);
        if(temp->right) st.push(temp->right); // we first push right coz stack is a LIFO DS and we need left node printed first before right node as it is a preorder traversal 
        if(temp->left) st.push(temp->left);
    }

    return ans;
}

int main()
{
    
    return 0;
}