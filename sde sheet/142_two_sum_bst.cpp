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

class BSTIterator
{
    stack<Node *> st;
    bool reversse = true;

public:
    BSTIterator(Node *root, int rev)
    {
        reversse = rev;
        pushall(root);
    }

    int next()
    {
        Node *temp = st.top();
        st.pop();
        if (reversse)
            pushall(temp->left);
        else
            pushall(temp->right);
        return temp->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }

    void pushall(Node *root)
    {
        while (root)
        {
            st.push(root);
            if (reversse)
                root = root->right;
            else
                root = root->left;
        }
    }
};

bool findTarget(Node *root, int k)
{
    BSTIterator l(root, 0);
    BSTIterator h(root, 1);

    int a = l.next(), b = h.next();
    while (a < b)
    {
        int x = a + b;
        if (x == k)
            return 1;
        else if (x > k)
            b = h.next();
        else
            a = l.next();
    }

    return 0;
}

int main()
{

    return 0;
}