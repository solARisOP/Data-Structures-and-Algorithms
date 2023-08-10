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

int widthOfBinaryTree(Node *root)
{
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    int ans = 1;
    while (!q.empty())
    {
        int n = q.size();
        pii p{-1, -1};
        int mini = q.front().second;
        
        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front().first;
            int num = q.front().second - mini;
            q.pop();

            if (!i) p.first = num;
            p.second = num;

            if (temp->left) q.push({temp->left, 1LL * 2 * num + 1});
            if (temp->right) q.push({temp->right, 2 * num + 2});
        }

        ans = max(ans, p.second - p.first + 1);
    }

    return ans;
}

int main()
{

    return 0;
}