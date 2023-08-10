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

vvi getTreeTraversal(Node *root){
    // Write your code here.
    vi ino, pre, post;
    stack<pair<Node*, int>> st;
    st.push({root, 1});
    while(!st.empty())
    {
        Node * temp = st.top().first;
        int num = st.top().second;

        if(num == 1)
        {
            pre.push_back(temp->val);
            st.top().second++;
            if(temp->left) st.push({temp->left, 1});
        }
        else if(num == 2)
        {
            ino.push_back(temp->val);
            st.top().second++;
            if(temp->right) st.push({temp->right, 1});
        }
        else
        {
            st.pop();
            post.push_back(temp->val);
        }
    }

    vvi ans = {ino, pre, post};

    return ans;
}

int main()
{
    
    return 0;
}