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

void bst_dll(Node * root, Node *& head)
{
    if(!root) return;

    bst_dll(root->right, head);

    root->right = head;
    if(head) head->left = root;
    head = root;

    bst_dll(root->left, head);
}

Node * merge_dll(Node * root1, Node * root2)
{
    Node * head = NULL;
    Node * tail = NULL;

    while(root1 && root2)
    {
        if(root1->data < root2->data)
        {
            if(!head)
            {
                head = root1;
                tail = root1;
                root1 = root1->right;
            }
            else
            {
                tail->right = root1;
                root1->left = tail;
                tail = root1;
                root1 = root1->right;
            }
        }
        else
        {
            if(!head)
            {
                head = root2;
                tail = root2;
                root2 = root2->right;
            }
            else
            {
                tail->right = root2;
                root2->left = tail;
                tail = root2;
                root2 = root2->right;
            }
        }
    }

    while(root1)
    {
        tail->right = root1;
        root1->left = tail;
        tail = root1;
        root1 = root1->right;
    }
    while(root2)
    {
        tail->right = root2;
        root2->left = tail;
        tail = root2;
        root2 = root2->right;
    }

    return head;
}

int count_nodes(Node * root)
{
    int count = 0;
    while(root)
    {
        count++;
        root = root->right;
    }
    return count;
}

Node * dll_bst(Node * &head, int n)
{
    if(n<=0 || !head) return NULL;

    Node * l = dll_bst(head, n/2);

    Node * root = head;
    root->left = l;
    head = head->right;

    root->right = dll_bst(head, n- n/2-1);

    return root;
}

Node *mergeBST(Node *root1, Node *root2){
    // Write your code here.
    Node * head1 = NULL;
    Node * head2 = NULL;
    bst_dll(root1, head1);
    bst_dll(root2, head2);

    Node * head = merge_dll(head1, head2);

    return dll_bst(head, count_nodes(head));
}

int main()
{
    
    return 0;
}