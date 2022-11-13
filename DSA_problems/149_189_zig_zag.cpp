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

vector<int> zigZagTraversal(Node *root)
{
    vi ans;
    if(!root) return ans;
    queue<Node *> q;
    q.push(root);

    while(!q.empty())
    {
        int size = q.size();
        int fl =0;
        vi level(size);
        for(int i =0; i<size; i++)
        {
            Node * temp = q.front();
            q.pop();
            if(fl == 1) level[size - i- 1] = temp->val;
            else level[i] = temp->val;

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);

        }
        fl = !fl;
        ans.insert(ans.end(), level.begin(), level.end());
    }
}

int main()
{

    return 0;
}