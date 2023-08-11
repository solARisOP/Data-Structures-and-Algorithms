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

vvi zigzagLevelOrder(Node *root)
{
    vvi ans;
    if (!root) return ans;

    queue<Node *> q;
    q.push(root);
    bool fl = 1;
    while (!q.empty())
    {
        int n = q.size();
        vi level(n);
        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front();
            q.pop();
            int ind = fl ? i : n - i - 1;
            level[ind] = temp->val;

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        
        fl = !fl;
        ans.push_back(level);
    }

    return ans;
}

int main()
{

    return 0;
}