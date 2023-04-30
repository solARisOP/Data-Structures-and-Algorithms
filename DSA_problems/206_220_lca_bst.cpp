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

Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   int a = (n1<n2) ? n1 : n2;
   int b = (n1>n2) ? n1 : n2;
   Node * temp = root;
   while(temp)
   {
       if(temp->data < a && temp->data < b) temp = temp->right;
       else if(temp->data > a && temp->data > b) temp = temp->left;
       else break;
   }
   
   return temp;
}

int main()
{
    
    return 0;
}