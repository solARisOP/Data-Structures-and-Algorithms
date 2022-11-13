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

vi diagonal(Node *root)
{
    // your code here
    vi ans;
    if(!root) return ans; 
    unordered_map<int, unordered_map<int, queue<int>>> mp;

    queue<pair<Node *, pair<int, int>>> q;

    q.push({root, {0, 0}});

    while (!q.empty())
    {
        int size = q.size();

        for(int i =0; i<size; i++)
        {
            Node * temp = q.front().first;
            int line = q.front().second.first;
            int level = q.front().second.second;

            q.pop();

            mp[line][level].push(temp->val);

            if(temp->left) q.push({temp->left, {line-1, level+1}});
            if(temp->right) q.push({temp->right, {line+1, level+1}});
        }
    }

    while(1)
    {
        while(1)
        {
            mp.find([line][level])
        }
    }
}

int main()
{

    return 0;
}