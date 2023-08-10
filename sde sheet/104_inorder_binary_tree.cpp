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
void inorder(Node *root, vi &ans)
{
    if (!root)
        return;

    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}

vector<int> inorderTraversal(Node *root)
{
    vi ans;
    inorder(root, ans);
    return ans;
}

// iterative
vector<int> inorderTraversal_iter(Node *root)
{
    vi ans;
    stack<Node *> st;

    while (1)
    {
        if(root)
        {
            st.push(root);
            root = root->left;
        }
        else
        {
            if (st.empty())
                break;
            root = st.top();
            st.pop();
            ans.push_back(root->val);
            root = root->right;
        }
    }
    return ans;
}

// morris
vector<int> inorderTraversal_morris(Node *root)
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
                curr = curr->left;
            }
            else
            {
                temp->right = NULL;
                ans.push_back(curr->val);
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