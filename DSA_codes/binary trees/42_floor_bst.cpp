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

int floorInBST(Node* root, int x)
{
    Node * curr = root;
    int floor = -1;
    while(curr)
    {
        if(x==curr->data) return x;
        else if(curr->data<x) 
        {
            floor = curr->data;
            curr = curr->right;
        }
        else curr = curr->left;

    }
        return floor;
    // Write your code here.
}

int main()
{
    
    return 0;
}