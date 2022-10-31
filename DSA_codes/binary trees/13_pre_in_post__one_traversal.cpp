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

vii traverse(Node* root)
{
    stack<pair<Node*, int>> st;
    vi pre, in, post;

    st.push({root, 1});

    while(!st.empty())
    {
        if(st.top().second == 1)
        {
            Node * temp = st.top().first;
            pre.push_back(temp->val);
            st.top().second++;
            if(temp->left) st.push({temp->left, 1}); 
        }

        else if(st.top().second == 2)
        {
            Node * temp = st.top().first;
            in.push_back(temp->val);
            st.top().second++;
            if(temp->right) st.push({temp->right, 1});
        }

        else
        {
            Node * temp = st.top().first;
            post.push_back(temp->val);
            st.pop();
        }
    }

    vii ans = {pre, in, post};

    return ans;
}

int main()
{
    
    return 0;
}