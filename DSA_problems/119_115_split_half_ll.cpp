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

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    *head1_ref = head;
    Node * slow =head;
    Node * fast = head->next;
    Node*r = head;
    while(fast != head && fast->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
        r = r->next->next;
    }
    
    *head2_ref = slow->next;
    slow->next = head;
    if(fast == head) r->next = *head2_ref;
    else fast->next =*head2_ref;
}    

int main()
{
    
    return 0;
}
