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

pair<int, int> solve(Node *root)
    {
        if (!root) return {0, 0};
    
        pair<int, int> l = solve(root->left);
        pair<int, int> r = solve(root->right);
    
        if (l.first == r.first) return {l.first + 1, root->data + max(l.second, r.second)};
        else if(l.first > r.first) return {l.first +1 , root->data + l.second};
        else return {r.first +1 , root->data + r.second};
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        // code here
        return solve(root).second;
    }

int main()
{

    return 0;
}