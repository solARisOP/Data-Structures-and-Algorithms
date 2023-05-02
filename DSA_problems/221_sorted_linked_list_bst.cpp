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

class LNode
{
    public:
        int data;
        LNode * next;

        LNode() : data(0), next(NULL){}
        LNode(int x) : data(x), next(NULL){}
        LNode(int x, LNode * a) : data(x), next(a){}
};

int count_nodes(LNode *head)
{
    int count = 0;

    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}

Node *solve(LNode *&head, int n)
{
    if (n <= 0 || !head) return NULL;

    Node *l = solve(head, n / 2);

    Node *root = new Node(head->data);
    root->left = l;
    head = head->next;

    root->right = solve(head, n - n / 2 - 1);

    return root;
}

Node *sortedListToBST(LNode *head)
{
    // code here
    return solve(head, count_nodes(head));
}

int main()
{

    return 0;
}