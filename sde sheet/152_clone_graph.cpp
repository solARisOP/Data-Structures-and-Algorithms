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
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

Node *cloneGraph(Node *node)
{
    if (!node)
        return NULL;
    unordered_map<Node *, Node *> mpp;
    queue<Node *> q;
    Node *root = new Node(node->val);
    mpp[node] = root;
    q.push(node);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        vector<Node *> neigh;
        for (auto it : temp->neighbors)
        {
            if (mpp[it])
                neigh.push_back(mpp[it]);
            else
            {
                Node *x = new Node(it->val);
                neigh.push_back(x);
                mpp[it] = x;
                q.push(it);
            }
        }
        mpp[temp]->neighbors = neigh;
    }

    return root;
}

int main()
{

    return 0;
}