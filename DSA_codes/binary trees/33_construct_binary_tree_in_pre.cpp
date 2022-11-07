#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node() : val(0), left(NULL), right(NULL) {}
    Node(int x) : val(x), left(NULL), right(NULL) {}
    Node(int x, Node *a, Node *b) : val(x), left(a), right(b) {}
};

Node *build(int i_start, int i_end, int p_start, int p_end, vi &in, vi &pre, unordered_map<int, int> &mp)
{
    if (i_start > i_end || p_start > p_end) return NULL;

    Node *root = new Node(pre[p_start]);

    int inroot = mp[root->val]; // the index for root
    int len_left = mp[pre[p_start]] - i_start; // the length of the inorder array remaining on the left of it after taking the root;

    root->left = build(i_start, inroot - 1, p_start + 1, p_start + len_left, in, pre, mp);
    root->right = build(inroot + 1, i_end, p_start + len_left + 1, p_end, in, pre, mp);

    return root;
}

Node *construct_binary_tree(vi inorder, vi preorder)
{
    unordered_map<int, int> mp;

    for (int i = 0; i< inorder.size(); i++) mp[inorder[i]] = i; // hashing the values for the inorder array

    return build(0, inorder.size() - 1, 0, preorder.size() - 1, inorder, preorder, mp);
}

int main()
{
    vi preorder = {3,9,20,15,7}, inorder = {9,3,15,20,7};
    construct_binary_tree(preorder, inorder);

    return 0;
}