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

int index_find(string s, int si, int ei)
{
    if(si>ei) return -1;
    int ind = -1;
    stack<char> st;
    for(int i=si; i<ei; i++)
    {
        if(s[i] == '(')st.push(s[i]);
        else if(s[i] == ')')
        {
            st.pop();
            if(st.empty())
            {
                ind = i;
                break;
            }
        }
    }

    return ind;
}

Node * tree_transform(string s, int si, int ei)
{
    if(si>ei) return NULL;

    int num=0;
    while(si<=ei && s[si]>='0' && s[ei]<='9')
    {
        num = num*10 + (s[si] - '0');
        si++;
    }

    Node * root = new Node(num);
    int ind = -1;
    if (si <= ei && s[si] == '(') ind = index_find(s, si, ei);
    if(ind != -1)
    {
        root->left = tree_transform(s, si+1, ind);

        root->right = tree_transform(s, ind+2, ei);
    }

    return root;
}

void preOrder(Node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->val);
    preOrder(node->left);
    preOrder(node->right);
}

int main()
{
    string s;
    cin>>s;
    Node * root = tree_transform(s, 0, s.size()-1);
    preOrder(root);
    return 0;
}