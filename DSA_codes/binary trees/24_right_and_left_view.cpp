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

void right_view_recurssive(int level, Node * root, queue<Node*> &q)
{
    if(!root) return;

    if(q.size() == level) q.push(root); // when the size of queue is equal to the level means we are visiting the level first time which automatically means it is the rightmost node then we store the node;
    if(root->right) right_view_recurssive(level+1, root->right, q);
    if(root->left) right_view_recurssive(level+1, root->left, q);
}

void left_view_recurssive(int level, Node * root, queue<Node*> &q)
{
    if(!root) return;

    if(q.size() == level) q.push(root);
    if(root->left) left_view_recurssive(level+1, root->left, q);
    if(root->right) left_view_recurssive(level+1, root->right, q);
}

vi right_view_iterative(Node * root)
{
    map<int, int> mp;
    queue<pair<int, Node*>> q;

    q.push({0, root});
    while(!q.empty())
    {
        int size = q.size();
        for(int i =0; i<size; i++)
        {
            Node * temp = q.front().second;
            int level = q.front().first;
            q.pop();

            mp[level] = temp->val;

            if(temp->left) q.push({level + 1, temp->left}); // first we store left than right because by this the map will automatically get updated when we will pick the atmost right node from the queue
            if(temp->right) q.push({level + 1, temp->right});
        }
    }

    vi ans;
    for(auto i : mp)
    {
        ans.push_back(i.second);
    }

    return ans;
}

vi left_view_iterative(Node * root)
{
    map<int, int> mp;
    queue<pair<int, Node*>> q;

    q.push({0, root});
    while(!q.empty())
    {
        int size = q.size();
        for(int i =0; i<size; i++)
        {
            Node * temp = q.front().second;
            int level = q.front().first;
            q.pop();

            mp[level] = temp->val;

            if(temp->right) q.push({level + 1, temp->right}); 
            if(temp->left) q.push({level + 1, temp->left});
        }
    }

    vi ans;
    for(auto i : mp)
    {
        ans.push_back(i.second);
    }

    return ans;
}

vi view(Node * root)
{
    queue<Node * > q;
    right_view_recurssive(0, root, q);
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