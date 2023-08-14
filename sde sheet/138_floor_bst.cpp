#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

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

int floorInBST(Node* root, int X)
{
    // Write your code here.
    Node* curr = root;
    int l = -1;
    while(curr)
    {
        if(curr->val >= X) 
        {
            if(curr->val == X) return X;
            curr = curr->left;
        } 
        else
        {
            l = curr->val;
            curr = curr->right;
        } 
    }

    return l;
}

int main()
{
    
    return 0;
}