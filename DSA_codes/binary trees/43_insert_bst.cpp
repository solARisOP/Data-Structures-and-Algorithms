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

Node *insertIntoBST(Node *root, int x)
{
    if (!root)
        return new Node(x);
    Node *curr = root;

    while (1)
    {
        if (x > curr->data)
        {
            if (curr->right)
                curr = curr->right;
            else
            {
                curr->right = new Node(x);
                break;
            }
        }
        else
        {
            if (curr->left)
                curr = curr->left;
            else
            {
                curr->left = new Node(x);
                break;
            }
        }
    }

    return root;
}

int main()
{

    return 0;
}
