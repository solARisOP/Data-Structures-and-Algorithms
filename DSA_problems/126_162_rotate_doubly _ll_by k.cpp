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

Node *rotateDLL(Node *start, int p)
{
    // Add your code here
    Node *e = start;
    while (e->next != NULL)
    {
        e = e->next;
    }
    e->next = start;
    start->prev = e;

    Node *x = start;
    while (p - 1)
    {
        x = x->next;
        p--;
    }
    Node *ans = x->next;
    x->next = NULL;
    ans->prev = NULL;
    
    return ans;
}

int main()
{
    
    return 0;
}