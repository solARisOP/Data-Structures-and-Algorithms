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

vii level_order(Node * root)
{
    vii ans;
    if(root == NULL) return ans;

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int size = q.size();
        vi level;
        for(int i =0; i<size; i++)
        {
            Node * temp = q.front();
            q.pop();

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            level.push_back(temp->val);
        }
        ans.push_back(level);
    }

    return ans;    
}


int main()
{

    return 0;
}