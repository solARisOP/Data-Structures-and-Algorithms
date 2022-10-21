#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

int getNthFromLast(Node *head, int c)
{
    // Your code here
    Node *p = head;
    Node *n = head;

    while (n)
    {
        if (c)
        {
            n = n->next;
            --c;
        }
        else
        {
            p = p->next;
            n = n->next;
        }
    }
    if (c)
        return -1;
    return p->data;
}

int main()
{

    return 0;
}