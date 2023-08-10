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
    Node *left;
    Node *right;

    Node() : val(0), left(NULL), right(NULL) {}
    Node(int x) : val(x), left(NULL), right(NULL) {}
    Node(int x, Node *a, Node *b) : val(x), left(a), right(b) {}
};

vector<vector<int>> verticalTraversal(Node *root)
{
    map<int, vi> mpp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int n = q.size();
        map<int, multiset<int>> create;
        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front().first;
            int lvl = q.front().second;
            q.pop();

            create[lvl].insert(temp->val);
            if (temp->left)
                q.push({temp->left, lvl - 1});
            if (temp->right)
                q.push({temp->right, lvl + 1});
        }
        for (auto it : create)
        {
            for (int x : it.second)
            {
                mpp[it.first].push_back(x);
            }
        }
    }

    vvi ans;
    for (auto it : mpp)
        ans.push_back(it.second);

    return ans;
}

int main()
{

    return 0;
}