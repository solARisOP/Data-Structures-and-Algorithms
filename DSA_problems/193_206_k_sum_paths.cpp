#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node() : data(0), left(NULL), right(NULL) {}
    Node(int x) : data(x), left(NULL), right(NULL) {}
    Node(int x, Node *a, Node *b) : data(x), left(a), right(b) {}
};

void solve(Node *root, vector<int> &path, int k, int &ans)
{
    if (!root)
        return;

    path.push_back(root->data);

    solve(root->left, path, k, ans);
    solve(root->right, path, k, ans);

    int f = 0;
    for (int j = path.size() - 1; j >= 0; j--)
    {
        f += path[j];
        if (f == k)
            ans++;
        ;
    }

    path.pop_back();
}

int sumK(Node *root, int k)
{
    // code here
    int ans = 0;
    vector<int> path;
    // unordered_map<int, int> mp;
    solve(root, path, k, ans);
    return ans;
}

// optimised
void solve(Node *root, int k, int sum, int &ans, unordered_map<int, int> &mp)
{
    if (root == NULL)
        return;

    sum += root->data;
    if (mp.find(sum - k) != mp.end())
    {
        ans += mp[sum - k];
    }

    mp[sum]++;
    solve(root->left, k, sum, ans, mp);
    solve(root->right, k, sum, ans, mp);
    mp[sum]--;
}
int sumK(Node *root, int k)
{
    unordered_map<int, int> mp;
    mp[0]++;
    int ans = 0;
    solve(root, k, 0, ans, mp);
    return ans;
}

int main()
{

    return 0;
}