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

void solve(Node* root, int k, int &ans, int &cnt)
{
    if(!root || ans!=-1) return;
    solve(root->right, k, ans, cnt);
    cnt++;
    if(cnt == k)
    {
        ans = root->val;
        return;
    }
    solve(root->left, k, ans, cnt);
    }
int KthLargestNumber(Node* root, int k) 
{
    // Write your code here.
    int cnt =0, ans =-1;
    solve(root, k, ans, cnt);
    return ans;
}


int main()
{
    
    return 0;
}