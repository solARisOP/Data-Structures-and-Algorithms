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

vi bottom_view(Node * root)
{
    map<int, int> mp;
    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        int line = it.second;
        Node * temp = it.first;

        mp[line] = temp->val;
        if(temp->left) q.push({temp->left, line - 1});
        if(temp->right) q.push({temp->right, line + 1});
    }

    vi ans;

    for(auto it : mp)
    {
        ans.push_back(it.second);
    }

    return ans;
}

int main()
{
    
    return 0;
}