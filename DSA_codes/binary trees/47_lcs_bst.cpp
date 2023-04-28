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

Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    int a = (p->data < q->data) ? p->data : q->data;
    int b = (p->data > q->data) ? p->data : q->data;
    Node *curr = root;
    while (curr)
    {
        if (a < curr->data && b < curr->data)
            curr = curr->left;
        else if (a > curr->data && b > curr->data)
            curr = curr->right;
        else
            break;
    }

    return curr;
}

int main()
{

    return 0;
}