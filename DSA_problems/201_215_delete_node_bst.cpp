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
    Node *temp = root->left;
    if (temp)
    {
        while (temp->right)
            temp = temp->right;
        temp->right = root->right;
        return root->left;
    }
    return root->right;
}

Node *deleteNode(Node *root, int key)
{
    if (!root) return NULL;
    if (root->data == key) return helper(root);
    
    Node *temp = root;

    while (temp)
    {
        if (temp->data > key)
        {
            if (temp->left && temp->left->data == key)
            {
                temp->left = helper(temp->left);
                break;
            }
            else temp = temp->left;
        }

        else
        {
            if (temp->right && temp->right->data == key)
            {
                temp->right = helper(temp->right);
                break;
            }
            else temp = temp->right;
        }
    }

    return root;
}

int main()
{
   
    return 0;
}