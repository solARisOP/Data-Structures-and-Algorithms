#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node * next;
        
};

Node *removeDuplicates(Node *head)
{
 // your code goes here
    Node *i = head;
    while(i != NULL)
    {
        while((i != NULL && i->next != NULL) && (i->data == i-> next->data))
        {
            Node *ptr = i->next;
            i->next = ptr->next;
            delete (ptr);
        }
        i = i->next;
    }
    return head;
}

int main()
{
    
    return 0;
}