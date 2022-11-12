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

vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int> ans;
    if (!root)
        return ans;
    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        int s = q.size();

        for (int i = 0; i < s; i++)
        {
            Node *t = q.front();
            q.pop();
            ans.push_back(t->val);
            if (t->right)
                q.push(t->right);
            if (t->left)
                q.push(t->left);
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{

    return 0;
}