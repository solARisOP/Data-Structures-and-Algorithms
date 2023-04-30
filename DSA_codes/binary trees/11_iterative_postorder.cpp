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

vi iter_postorder(Node * root)
{
    vi ans;
    if(root == NULL) return ans;

    stack <Node*> st1, st2;
    st1.push(root);

    while(!st1.empty())
    {
        Node * curr = st1.top();
        st1.pop();
        if(curr->left) st1.push(curr->left);
        if(curr->right) st1.push(curr->right);
        st2.push(curr);
    }

    while(!st2.empty())
    {
        ans.push_back(st2.top()->val);
        st2.pop();
    }

    return ans;
}

int main()
{
    
    return 0;
}