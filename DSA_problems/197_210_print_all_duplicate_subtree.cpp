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

string solve(Node *root, unordered_map<string, int> &mp, vector<Node *> &ans)
{
    if (!root)return "#";
    
    string l = solve(root->left, mp, ans);
    string r = solve(root->right, mp, ans);

    string s = to_string(root->data) + "," + l + "," + r;

    if (mp[s] == 1) ans.push_back(root);
    mp[s]++;

    return s;
}
vector<Node *> printAllDups(Node *root)
{
    // Code here
    unordered_map<string, int> mp;
    vector<Node *> ans;

    solve(root, mp, ans);

    return ans;
}

int main()
{

    return 0;
}