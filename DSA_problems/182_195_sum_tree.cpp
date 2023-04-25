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

int solve(Node *node)
{
    if (!node)
        return 0;

    int temp = node->data;
    node->data = solve(node->left) + solve(node->right);

    return temp + node->data;
}
void toSumTree(Node *node)
{
    // Your code here
    solve(node);
}

int main()
{
    
    return 0;
}

