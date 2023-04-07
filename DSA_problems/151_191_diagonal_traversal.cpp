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
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        
        while (temp)
        {
            if (temp->left) q.push(temp->left);
            ans.push_back(temp->val);
            temp = temp->right;
        }
    }

    return ans;
}

int main()
{

    return 0;
}