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

class BSTIterator 
{
    private:
        stack<Node*> st;
        void pushall(Node * root)
        {
            while(root)
            {
                st.push(root);
                root = root->left;
            } 
        }

    public:
        BSTIterator(Node* root) {
            Node * curr = root;
            pushall(curr);
        }
        
        int next() {
            Node * temp = st.top();
            st.pop();
            if(temp->right) pushall(temp->right);
            return temp->data;
        }
        
        bool hasNext() {
            return !st.empty();
        }

};

int main()
{
    
    return 0;
}