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

Node *pre = NULL;
void flatten_recursive(Node *root)
{
    if (!root)
        return;

    flatten_recursive(root->right);
    flatten_recursive(root->left);

    root->right = pre;
    root->left = NULL;

    pre = root;
}

void flatten_iterative(Node *root)
{
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *temp = st.top();
        st.pop();

        if (temp->right)
            st.push(temp->right);

        if (temp->left)
            st.push(temp->left);

        if (!st.empty())
            temp->right = st.top();

        temp->left = NULL;
    }
}

void flatten_morris(Node *root)
{
    Node *curr = root;
    while (curr)
    {
        if (curr->left)
        {
            Node *prev = curr->left;
            while (prev->right) prev = prev->right;

            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }

        curr = curr->right;
    }
}

int main()
{

    return 0;
}