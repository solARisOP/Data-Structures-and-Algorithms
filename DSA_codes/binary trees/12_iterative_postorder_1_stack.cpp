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
    vi post;
    stack<Node*> st;
    Node* curr;
    Node* temp;

    while(curr || !st.empty())
    {
        if(curr)
        {
            st.push(curr);
            curr = curr->left;
        }

        else
        {
            temp = st.top()->right;
            if(!temp) // if the right is NULL means the left was also NULL that's why we came to right , so we start storing the postorder
            {
                temp = st.top();
                st.pop();
                post.push_back(temp->val);

                while((!st.empty()) && (temp == st.top()->right)) // we are backtracking and storing the post order traversal
                {
                    temp = st.top();
                    st.pop();
                    post.push_back(temp->val);
                }
            }

            else curr = temp; // if it is not NULL then we assign it to the curr(our aim is to go to the extreme left as possible)
        }
    }

    return post;
}

int main()
{
    
    return 0;
}