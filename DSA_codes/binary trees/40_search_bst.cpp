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

Node *searchBST(Node *root, int x)
{
    Node *curr = root;
    while (curr != NULL)
    {
        if (x == curr->data)
            return curr;
        else if (x < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    return curr;
}

int main()
{

    return 0;
}