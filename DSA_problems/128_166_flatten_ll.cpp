#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *bottom;
    Node(int a)
    {
        data = a;
        next = NULL;
        bottom = NULL;
    }
};

#define bt bottom

Node *merge(Node *a, Node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    Node *ans = new Node(-1);
    Node *temp = ans;
    while (a && b)
    {
        if (a->data < b->data)
        {
            temp->bt = a;
            temp = a;
            a = a->bt;
        }

        else
        {
            temp->bt = b;
            temp = b;
            b = b->bt;
        }
    }

    while (a)
    {
        temp->bt = a;
        temp = a;
        a = a->bt;
    }

    while (b)
    {
        temp->bt = b;
        temp = b;
        b = b->bt;
    }
    ans = ans->bt;
    return ans;
}


Node *flatten(Node *root)
{
    // Your code here
    if (root->next == NULL)
        return root;

    Node *temp = root;
    Node *ans = temp;
    temp = temp->next;

    while (temp)
    {
        ans = merge(ans, temp);
        temp = temp->next;
    }

    return ans;
}

int main()
{

    return 0;
}