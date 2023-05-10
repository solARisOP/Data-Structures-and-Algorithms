#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node *cloneGraph(Node *node)
{

    if (!node)
        return NULL;

    Node *start = new Node(node->val);

    unordered_map<Node *, Node *> mpp;
    mpp[node] = start;

    queue<Node *> q;
    q.push(node);

    while (!q.empty())
    {
        Node *parent = q.front();
        q.pop();

        vector<Node *> childs;

        for (auto it : parent->neighbors)
        {
            if (mpp.find(it) == mpp.end())
            {
                Node *neigh = new Node(it->val);
                q.push(it);
                mpp[it] = neigh;
                childs.push_back(neigh);
            }
            else
            {
                childs.push_back(mpp[it]);
            }
        }
        Node *clone = mpp[parent];

        clone->neighbors.insert(clone->neighbors.end(), childs.begin(), childs.end());
    }

    return start;
}

int main()
{

    return 0;
}