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

void left_border(Node * root, vi &res)
{
    if(!root) return;

    Node * curr = root;
    while(curr)
    {
        if(curr->left || curr->right) res.push_back(curr->val);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

void right_border(Node * root, vi &res)
{
    if(!root) return;
    Node * curr = root;
    stack<Node *> s;
    while(curr)
    {
        if(curr->left || curr->right)s.push(curr);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }

    while(!s.empty())
    {
        res.push_back(s.top()->val);
        s.pop();
    } 
}

void leaf_traverse(Node * root, vi &res)
{
    
    if(!root->left && !root->right)
    {
        res.push_back(root->val);
        return;
    } 
    if(root->left) leaf_traverse(root->left, res); 
    if(root->right) leaf_traverse(root->right, res); 
}

vi border_traversal(Node * root)
{
    vi res;
    if(!root) return res;

    left_border(root, res);
    leaf_traverse(root, res);
    right_border(root->right, res);

    return res;
}

int main()
{
    
    return 0;
}
