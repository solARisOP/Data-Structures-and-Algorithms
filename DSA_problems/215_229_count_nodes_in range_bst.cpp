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

void solve(Node *root, int l, int h, int &count)
{
    if (!root)
        return;
    if (l <= root->data && root->data <= h)
        count++;

    solve(root->left, l, h, count);
    solve(root->right, l, h, count);
}
int getCount(Node *root, int l, int h)
{
    // your code goes here
    int count = 0;
    solve(root, l, h, count);
    return count;
}

int main()
{

    return 0;
}