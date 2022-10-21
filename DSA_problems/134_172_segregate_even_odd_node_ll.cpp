#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void print(Node * i)
{
    while(i)
    {
        cout<<i->data<<" ";
        i = i->next;
    }
}

Node *divide(Node *head)
{
    // code here
    if(head->next == NULL) return head;

    Node *temp = new Node(-1);
    temp->next = head;
    Node *i = temp;
    Node *j = head;
    Node *e = head;
    Node *f = NULL;

    while(e->next)e = e->next;
    
    int fl = 1;
    while(j && j != e)
    {
        if((j->data) % 2 == 1)
        {
            if(!fl && j == f) break;
            i->next = j->next;
            e->next = j;
            j->next = NULL;
            e = j;
            j = i->next;
            if(fl)
            {
                f = e;
                fl =0;
            }
        }
        else
        {
            i = i->next;
            j = j->next;
        }
    }
    temp = temp -> next;
    return temp;
}

int main()
{
    Node * head = new Node (17);
    head -> next = new Node (15);
    head -> next -> next = new Node (8);
    head -> next -> next ->next= new Node (9);
    head -> next -> next ->next ->next= new Node (2);
    head -> next -> next ->next ->next -> next= new Node (4);
    head -> next -> next ->next ->next -> next -> next= new Node (6);
    // print(head);ṣ

    head = divide(head);

    print(head);
    return 0;
}