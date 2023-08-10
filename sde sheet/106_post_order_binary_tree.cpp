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

// recursive
void postorder(Node *root, vi &ans)
{
    if (!root)
        return;

    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->val);
}
vector<int> postorderTraversal(Node *root)
{
    vi ans;
    postorder(root, ans);
    return ans;
}

// iterative
vector<int> postorderTraversal_iter(Node *root)
{
    vi ans;
    if(!root) return ans;
    stack<Node*> st;
    st.push(root);

    while(!st.empty())
    {
        Node* temp = st.top();
        ans.push_back(temp->val);
        st.pop();
        if(temp->left) st.push(temp->left);
        if(temp->right) st.push(temp->right);
    }
    reverse(begin(ans), end(ans));
    return ans;
}

// morris
vector<int> postorderTraversal_morris(Node *root)
{
    vi ans;
    
    Node *curr = root;
    while (curr)
    {
        if (!curr->right)
        {
            ans.push_back(curr->val);
            curr = curr->left;
        }
        else
        {
            Node *temp = curr->right;
            while (temp->left && temp->left != curr)
                temp = temp->left;
            if (!temp->left)
            {
                temp->left = curr;
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                temp->left = NULL;
                curr = curr->left;
            }
        }
    }
    reverse(begin(ans), end(ans));
    return ans;
}

int main()
{

    return 0;
}