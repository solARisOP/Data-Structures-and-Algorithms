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

vii vertical_traversal(Node * root)
{
    map<int, map<int, multiset<int>>> mp;
    queue<pair<Node*, pair<int, int>>> q;

    q.push({root, {0, 0}});

    while(!q.empty())
    {
        auto it =  q.front();
        q.pop();
        int x = it.second.first, y = it.second.second; 
        mp[x][y].insert(it.first->val);

        if(it.first->left) q.push({it.first->left, {x-1, y+1}});
        if(it.first->right) q.push({it.first->right, {x+1, y+1}});
    }

    vii ans;

    for(auto a : mp)
    {
        vi col;
        for(auto b : a.second)
        {
            col.insert(col.end(), b.second.begin(), b.second.end());
        }
        ans.push_back(col);
    }

    return ans;
}

int main()
{
    
    return 0;
}