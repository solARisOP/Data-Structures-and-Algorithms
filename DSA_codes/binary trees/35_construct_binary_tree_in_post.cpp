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

Node *build(int i_start, int i_end, int p_start, int p_end, vi &in, vi &post, unordered_map<int, int> &mp)
{
    if (i_start > i_end || p_start > p_end) return NULL;

    Node *root = new Node(post[p_end]);

    int inroot = mp[root->val]; // the index for root
    int len_left = mp[root->val] - i_start; // the length of the inorder array remaining on the left of it after taking the root;

    root->left = build(i_start, inroot - 1, p_start, p_start + len_left - 1, in, post, mp);
    root->right = build(inroot + 1, i_end, p_start + len_left, p_end - 1, in, post, mp);

    return root;
}

Node *construct_binary_tree(vi inorder, vi postorder)
{
    unordered_map<int, int> mp;

    for (int i = 0; i< inorder.size(); i++) mp[inorder[i]] = i; // hashing the values for the inorder array

    return build(0, inorder.size() - 1, 0, postorder.size() - 1, inorder, postorder, mp);
}

int main()
{
    
    return 0;
}