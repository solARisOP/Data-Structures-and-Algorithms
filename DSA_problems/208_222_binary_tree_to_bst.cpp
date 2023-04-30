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

vector<int> in;
void inorder(Node *root)
{
    if (!root) return;

    inorder(root->left);
    in.push_back(root->data);
    inorder(root->right);
}
Node *binaryTreeToBST(Node *root)
{
    // Your code goes here
    inorder(root);
    sort(in.begin(), in.end());
    int i = 0;
    Node *temp = root;
    while (temp)
    {
        if (!temp->left)
        {
            temp->data = in[i++];
            temp = temp->right;
        }
        else
        {
            Node *prev = temp->left;
            while (prev->right && prev->right != temp)
                prev = prev->right;

            if (!prev->right)
            {
                prev->right = temp;
                temp = temp->left;
            }
            else
            {
                prev->right = NULL;
                temp->data = in[i++];
                temp = temp->right;
            }
        }
    }

    return root;
}

int main()
{

    return 0;
}