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

Node *inOrderSuccessor(Node *root, Node *x)
{
    // Your code here
    int val = x->data;
    Node *ans = NULL;

    while (root)
    {
        if (root->data <= val)
            root = root->right;
        else
        {
            ans = root;
            root = root->left;
        }
    }
    return ans;
}

int main()
{

    return 0;
}