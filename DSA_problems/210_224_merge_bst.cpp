#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node() : data(0), left(NULL), right(NULL) {}
    Node(int x) : data(x), left(NULL), right(NULL) {}
    Node(int x, Node *a, Node *b) : data(x), left(a), right(b) {}
};

void left_in(Node *root, stack<Node *> &st)
{
    if (!root)
        return;
    while (root)
    {
        st.push(root);
        root = root->left;
    }
}
vector<int> merge(Node *root1, Node *root2)
{
    // Your code here
    stack<Node *> st1, st2;
    left_in(root1, st1);
    left_in(root2, st2);

    vi ans;
    while (!st1.empty() || !st2.empty())
    {
        if (st2.empty() || (!st1.empty() && st1.top()->data < st2.top()->data))
        {
            Node *temp = st1.top();
            ans.push_back(temp->data);
            st1.pop();
            left_in(temp->right, st1);
        }
        else
        {
            Node *temp = st2.top();
            ans.push_back(temp->data);
            st2.pop();
            left_in(temp->right, st2);
        }
    }

    return ans;
}

int main()
{

    return 0;
}