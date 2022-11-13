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

void rightView_recursive(int level, Node *root, vi &ans)
{
    if (!root)return;

    if (ans.size() == level)ans.push_back(root->val);
    rightView_recursive(level+1, root->right, ans);
    rightView_recursive(level+1, root->left, ans);
}

vi rightView_iterative(Node * root)
{
    vi ans;
    map<int , int> mp;
    queue<pair<int , Node *>> q;

    q.push({0, root});
    while(!q.empty())
    {
        int size = q.size();

        for(int i =0; i< size; i++)
        {
            Node * temp = q.front().second;
            int level = q.front().first;

            mp[level] = temp->val;

            if(temp->left) q.push({level +1, temp->left});
            if(temp->right) q.push({level +1, temp->right});
        }
    }

    for(auto i : mp) ans.push_back(i.second);

    return ans;
}

int main()
{

    return 0;
}