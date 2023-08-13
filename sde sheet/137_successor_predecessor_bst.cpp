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

// recurssive
void solve(Node* root, pii &ans, int key)
{
    if(!root || ans.second!= -1) return;
    solve(root->left, ans, key);
    if(root->val<key) ans.first = root->val;
    else if(ans.second == -1 && root->val>key) 
    {
        ans.second = root->val;
        return;
    }    
    solve(root->right, ans, key);
}
pii predecessorSuccessor(Node *root, int key)
{
    // Write your code here.
    pii ans = {-1,-1};
    solve(root, ans, key);
    return ans;
}

// iterative
pii predecessorSuccessor(Node *root, int key)
{
    // Write your code here.
    int succ = -1, pred = -1;
    Node* curr = root;
    while(curr)
    {
        if(curr->val >= key) curr = curr->left;
        else{
            pred = curr->val;
            curr = curr->right;
        }
    }
    curr = root;
    while(curr)
    {
        if
        (curr->val <= key) curr = curr->right;
        else{
            succ = curr->val;
            curr = curr->left;
        }
    }
    return {pred, succ};
}

int main()
{
    
    return 0;
}