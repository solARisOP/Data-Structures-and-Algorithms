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

void findPreSuc(Node* root, Node*& pre, Node*& suc, int x)
{

    // Your code goes here
    pre = suc = NULL;
    Node * temp = root;
    while(temp)
    {
        if(temp->data < x)
        {
            pre = temp;
            temp = temp->right;
        }
        else temp = temp->left;
    }
    
    temp = root;
    while(temp)
    {
        if(temp->data > x)
        {
            suc = temp;
            temp = temp->left;
        }
        else temp = temp->right;
    }

}

int main()
{
    
    return 0;
}