#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int a)
    {
        data = a;
        next = NULL;
    }
};

Node *rev(Node *head)
{
    Node *p = NULL;
    Node *n = NULL;

    while (head != NULL)
    {
        n = head->next;
        head->next = p;
        p = head;
        head = n;
    }
    return p;
}

Node *compute(Node *head)
{
    // your code goes here
    if (head->next == NULL)
        return head;
    Node *rev_head = rev(head);
    Node *i = rev_head;
    Node *j = rev_head->next;
    while (j)
    {
        if (i->data > j->data)
        {
            i->next = j->next;
            delete (j);
            j = i->next;
        }
        else
        {
            i = i->next;
            j = j->next;
        }
    }

    head = rev(rev_head);
    return head;
}

int main()
{

    return 0;
}