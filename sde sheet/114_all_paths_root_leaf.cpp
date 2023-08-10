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

void solve(Node * root, vector <string>& ans, string &s)
{
    if(!root) return;
    int n = s.size();
    s+=to_string(root->val)+" ";

    solve(root->left, ans, s);
    solve(root->right, ans, s);

    if(!root->left && !root->right) ans.push_back(s);
    s.resize(n);
}

vector <string> allRootToLeaf(Node* root) {
    // Write your code here.
    vector <string> ans;
    string s;
    solve(root, ans, s);
    return ans;
}

int main()
{
    string s = "abcd";
    int x = -109;
    string ch = to_string(x);
    cout<<ch;
    return 0;
}