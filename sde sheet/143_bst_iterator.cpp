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

class BSTIterator {
    stack<Node*> st;
public:
    BSTIterator(Node* root) {
        pushall(root);  
    }
    
    int next() {
        Node* temp = st.top();
        st.pop();
        pushall(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

    void pushall(Node* root)
    {
        while(root)
        {
            st.push(root);
            root = root->left;
        }
    }
};

int main()
{
    
    return 0;
}