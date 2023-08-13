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
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
    Node(int x, Node *a, Node *b, Node *n) : val(x), left(a), right(b), next(n) {}
};

// level order traversal using queue
Node *connect(Node *root)
{
    if (!root)
        return root;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size() - 1;
        Node *temp = q.front();
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
        q.pop();
        for (int i = 0; i < n; i++)
        {
            Node *tx = q.front();
            q.pop();
            temp->next = tx;
            if (tx->left)
                q.push(tx->left);
            if (tx->right)
                q.push(tx->right);
            temp = tx;
        }
    }

    return root;
}

// recursive
void solve(Node *root)
{
    if (!root)
        return;
    if (root->next && root->right)
        root->right->next = root->next->left;
    if (root->left)
        root->left->next = root->right;
    solve(root->left);
    solve(root->right);
}
Node *connect(Node *root)
{
    solve(root);
    return root;
}

// most optimized T.C - O(N), S.C - O(1)
Node *connect(Node *root)
{

    Node *curr = root;
    while (curr)
    {
        Node *temp = curr;
        while (temp)
        {
            if (temp->next && temp->right)
                temp->right->next = temp->next->left;
            if (temp->left)
                temp->left->next = temp->right;
            temp = temp->next;
        }
        curr = curr->left;
    }
    return root;
}
int main()
{

    return 0;
}