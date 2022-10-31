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

void parentmark(Node * root, unordered_map<Node*, Node*> &mp)
{
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node * temp = q.front();
        q.pop();

        if(temp->left)
        {
            mp[temp->left] = temp;
            q.push(temp->left);
        } 

        if(temp->right)
        {
            mp[temp->right] = temp;
            q.push(temp->right);
        } 
    }
}

vi nodes_k_dist(Node * root, Node * target, int k)
{
    unordered_map<Node*, Node*> mp;
    parentmark(root, mp);

    queue<Node*> q;
    unordered_map<Node*, bool> vis;
    q.push(root);
    vis[root]++;
    int dist = 0;
    while(!q.empty())
    {
        int size = q.size();
        if(dist++ == k) break;

        for(int i=0; i<size; i++)
        {
            Node * temp = q.front();
            q.pop();

            if(temp->left && !vis[temp->left])
            {
                vis[temp->left]++;
                q.push(temp->left);
            }
            if(temp->right && !vis[temp->right])
            {
                vis[temp->right]++;
                q.push(temp->right);
            }
            if(mp[temp] && !vis[mp[temp]])
            {
                vis[mp[temp]]++;
                q.push(mp[temp]);
            }
        }
    }

    vi ans;
    while(!q.empty())
    {
        ans.push_back(q.front()->val);
        q.pop();
    }

    return ans;
}


int main()
{
    
    return 0;
}