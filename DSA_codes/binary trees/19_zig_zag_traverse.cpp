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

vii zig_zag(Node * root)
{
    queue<Node *> q;
    vii ans;

    q.push(root);

    int flag =1;
    while(!q.empty())
    {
        int size = q.size();
        vi level(size);

        for(int i =0; i<size; i++)
        {
            Node* temp = q.front();
            q.pop();

            if(flag) level[i] = temp->val;
            else level[size - 1 - i] = temp->val;

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }

        flag = 1 - flag;
        ans.push_back(level);
    }

    return ans;
}

int main()
{
    
    return 0;
}