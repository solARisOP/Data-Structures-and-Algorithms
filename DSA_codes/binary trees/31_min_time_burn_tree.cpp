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

void parent_mark(Node *root, unordered_map<Node *, Node *> &mp)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->left)
        {
            q.push(temp->left);
            mp[temp->left] = root;
        }
        if (temp->right)
        {
            q.push(temp->right);
            mp[temp->right] = root;
        }
    }
}

int min_time_burn_tree(Node* root, Node* start)
{
    unordered_map<Node *, Node *> mp;
    parent_mark(root, mp);
    unordered_map<Node *, bool> vis;
    queue<Node *> q;
    q.push(start);
    vis[start] = 1;
    int time = 0;
    while (!q.empty())
    {
        int size = q.size();
        int fl = 0;

        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();

            if (temp->left && !vis[temp->left])
            {
                fl = 1;
                vis[temp->left] = 1;
                q.push(temp->left);
            }
            if (temp->right && !vis[temp->right])
            {
                fl = 1;
                vis[temp->right] = 1;
                q.push(temp->right);
            }
            if (mp[temp] && !vis[mp[temp]])
            {
                fl = 1;
                vis[mp[temp]] = 1;
                q.push(mp[temp]);
            }
        }

        if(fl) time++;
    }

    return time;
}

int main()
{
    
    return 0;
}