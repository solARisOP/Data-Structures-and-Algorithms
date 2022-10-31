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

bool path_trace(Node * root, vi path, int x)
{
    if(!root) return 0;

    path.push_back(root->val); // storing the path

    if(root->val == x) return true; // if value matches then we got our node and we wouldn't have to go any further so we return true;

    if(path_trace(root->left, path, x) || path_trace(root->right, path, x)) return true; // if we got any one true means we found our path so we return true as we dont go any further


    path.pop_back(); // if that return true doen't happen then we pop the element out and return false 
    return false;
}

vi root_to_node(Node * root, int x)
{
    vi path;
    if(!root) return path;
    path_trace(root, path, x);
}

int main()
{
    
    return 0;
}