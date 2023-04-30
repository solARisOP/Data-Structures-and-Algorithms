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

void inorder(Node *root, vector<int> &in)
{
    if (!root)
        return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}
int countPairs(Node *root1, Node *root2, int x)
{
    vector<int> a, b;
    inorder(root1, a);
    inorder(root2, b);
    int i = 0, j = b.size() - 1, ans = 0;

    while (i < a.size() && j >= 0)
    {
        if ((a[i] + b[j]) < x)
            i++;
        else if ((a[i] + b[j]) > x)
            j--;
        else
        {
            ans++;
            i++, j--;
        }
    }

    return ans;
}

int main()
{

    return 0;
}