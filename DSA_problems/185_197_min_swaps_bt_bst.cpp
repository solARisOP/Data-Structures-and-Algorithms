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

Node *solve(vector<int> &A, int i, int n)
{
    if (i >= n)
        return NULL;

    Node *root = new Node(A[i]);

    root->left = solve(A, 2 * i + 1, n);
    root->right = solve(A, 2 * i + 2, n);

    return root;
}

void inorder(Node *root, vector<int> &in)
{
    if (!root)
        return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}
int minSwaps(vector<int> &A, int n)
{
    // Write your code here
    Node *root = solve(A, 0, n);
    vector<int> in;

    inorder(root, in);

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[in[i]] = i;

    sort(in.begin(), in.end());
    int swaps = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp[in[i]] != i)
        {
            swaps++;
            swap(in[i], in[mp[in[i]]]);
            --i;
        }
    }
    return swaps;
}

int main()
{

    return 0;
}