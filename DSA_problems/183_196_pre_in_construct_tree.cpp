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

Node *solve(int in_i, int in_j, int pre_i, int pre_j, int pre[], unordered_map<int, queue<int>> &mp)
{
    if (in_i > in_j || pre_i > pre_j)
        return NULL;

    Node *root = new Node(pre[pre_i]);
    int ind = mp[root->data].front();
    int len_left = mp[root->data].front() - in_i;
    mp[root->data].pop();

    root->left = solve(in_i, ind - 1, pre_i + 1, pre_i + len_left, pre, mp);
    root->right = solve(ind + 1, in_j, pre_i + len_left + 1, pre_j, pre, mp);

    return root;
}

Node *buildTree(int in[], int pre[], int n)
{
    unordered_map<int, queue<int>> mp;
    for (int i = 0; i < n; i++)
        mp[in[i]].push(i);

    return solve(0, n - 1, 0, n - 1, pre, mp);
}

int main()
{
    
    return 0;
}