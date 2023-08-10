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
void preorder(Node *root, vi &ans)
{
    if (!root)
        return;

    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}

vector<int> preorderTraversal(Node *root)
{
    vi ans;
    preorder(root, ans);
    return ans;
}

// iterative
vector<int> preorderTraversal_iter(Node *root)
{
    vi ans;
    if (!root)
        return ans;
    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        Node *temp = st.top();
        ans.push_back(temp->val);
        st.pop();
        if (temp->right)
            st.push(temp->right);
        if (temp->left)
            st.push(temp->left);
    }
    return ans;
}

// morris
vector<int> preorderTraversal_morris(Node *root)
{
    vi ans;
    Node *curr = root;
    while (curr)
    {
        if (!curr->left)
        {
            ans.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            Node *temp = curr->left;
            while (temp->right && temp->right != curr)
                temp = temp->right;
            if (!temp->right)
            {
                temp->right = curr;
                ans.push_back(curr->val);
                curr = curr->left;
            }
            else
            {
                temp->right = NULL;
                curr = curr->right;
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}