#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node * next;
};

node * last_to_first(node * head)
{
    node * i = head;
    node * j = head;

    while(i->next != NULL)
    {
        j = i;
        i = i->next;
    }
    i ->next = head;
    head = i;
    j ->next = NULL;

    return head;
}

int main()
{
    
    return 0;
}