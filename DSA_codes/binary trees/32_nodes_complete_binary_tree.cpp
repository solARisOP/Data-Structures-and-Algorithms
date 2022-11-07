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

int left_height(Node * root)
{
    int h = 0;
    while(root)
    {
        h++;
        root = root->left;
    }

    return h;
}

int right_height(Node * root)
{
    int h = 0;
    while(root)
    {
        h++;
        root = root->right;
    }

    return h;
}

int count_nodes(Node * root)
{
    if(!root) return 0;

    int lh = left_height(root);
    int rh = right_height(root);

    if(lh == rh) return (1 << lh) - 1; // if left height is equal to right height then the no. of nodes in this subtree is 2^h - 1

    return 1 + count_nodes(root->left) + count_nodes(root->right); // if not equal then we go further for counting nodes of left and right nodes and then sum them up with 1 as this particular node is counted then return them
}
// above algo is of O((log N)^2) which is less than linear time

int main()
{
    
    return 0;
}