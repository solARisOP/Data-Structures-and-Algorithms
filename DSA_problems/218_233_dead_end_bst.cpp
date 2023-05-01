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

void check(Node *root, int mini, int maxi, bool &ans)
{
    if (!root || ans) return;
    
    if (!root->left && !root->right)
    {
        if ((root->data == mini + 1 || root->data == 1) && root->data == maxi - 1)
        {
            ans = 1;
            return;
        }
    }

    check(root->left, mini, root->data, ans);
    check(root->right, root->data, maxi, ans);
}

bool isDeadEnd(Node *root)
{
    // Your code here
    bool ans = 0;
    check(root, INT_MIN, INT_MAX, ans);
    return ans;
}

int main()
{

    return 0;
}