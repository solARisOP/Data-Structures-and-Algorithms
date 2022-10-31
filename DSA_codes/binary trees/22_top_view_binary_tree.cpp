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

vi top_view(Node * root)
{
    map<int, int> mp;
    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while(!q.empty())
    {
        auto it = q.front();
        q.pop();

        if(!mp[it.second]) mp[it.second] = it.first->val;

        if(it.first->left) q.push({it.first->left, it.second - 1});
        if(it.first->right) q.push({it.first->right, it.second + 1});
    }

    vi ans;
    for(auto i : mp)
    {
        ans.push_back(i.second);
    }

    return ans;
}

int main()
{
    
    return 0;
}