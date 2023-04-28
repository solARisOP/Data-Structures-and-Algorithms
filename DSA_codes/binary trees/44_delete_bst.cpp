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

Node *helper(Node *root)
{
    Node *temp = root->right;
    Node *r = root->left;
    if (r)
    {
        while (r->right)
            r = r->right;
        r->right = temp;
        return root->left;
    }
    return root->right;
}

Node *deleteNode(Node *root, int key)
{
    if (!root)
        return NULL;
    if (root->data == key)
        return helper(root);

    Node *curr = root;
    while (curr)
    {
        if (key > curr->data)
        {
            if (curr->right && curr->right->data == key)
            {
                curr->right = helper(curr->right);
                break;
            }
            else
                curr = curr->right;
        }
        else
        {
            if (curr->left && curr->left->data == key)
            {
                curr->left = helper(curr->left);
                break;
            }
            else
                curr = curr->left;
        }
    }

    return root;
}

int main()
{

    return 0;
}