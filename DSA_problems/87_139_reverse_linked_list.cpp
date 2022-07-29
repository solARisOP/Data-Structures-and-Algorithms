#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
};

// iterative
Node *reverseList(Node *head)
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

// recursive
Node *reverse_return(Node *head, Node *p)
{
    if (head == NULL)
    {
        return p;
    }

    Node *n = head->next;
    head->next = p;
    p = head;

    return reverse_return(n, p);
}

Node *reverseList2(Node *head)
{
    return reverse_return(head, NULL);
}

int main()
{
    
    return 0;
}