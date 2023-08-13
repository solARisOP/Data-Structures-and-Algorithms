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

Node *searchBST(Node *root, int val)
{
    Node *curr = root;
    while (curr)
    {
        if (val == curr->val)
            return curr;
        else if (val < curr->val)
            curr = curr->left;
        else
            curr = curr->right;
    }

    return NULL;
}

int main()
{

    return 0;
}