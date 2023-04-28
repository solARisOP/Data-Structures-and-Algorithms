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

int findCeil(Node *root, int x){
    // Write your code here.
    Node * curr = root;
    int ceil = -1;
    while(curr)
    {
        if(x == curr->data) return x;
        else if(curr->data>x)
        {
            ceil = curr->data;
            curr = curr->left;
        }
        else curr = curr->right;

    }

    return ceil;
}

int main()
{
    
    return 0;
}