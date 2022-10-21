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

vi iter_inorder(Node * root)
{
    Node * curr  = root;
    vi ans;
    stack <Node*> st;
    while(1)
    {
        if(curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            if(st.empty()) break;
            curr = st.top();
            st.pop();
            ans.push_back(curr->val);
            curr = curr -> right;
        }
    }

    return ans;
}


int main()
{
    
    return 0;
}