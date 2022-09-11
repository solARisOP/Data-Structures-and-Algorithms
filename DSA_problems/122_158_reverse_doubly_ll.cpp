#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int a)
    {
        data = a;
        next = NULL;
        prev = NULL;
    }
};

Node *reverseDLL(Node *head)
{
    // Your code here
    Node *prv = NULL;
    Node *nxt = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        nxt = curr->next;
        Node *x = curr->next;
        curr->next = prv;
        curr->prev = x;
        prv = curr;
        curr = nxt;
    }

    return prv;
}

int main()
{

    return 0;
}