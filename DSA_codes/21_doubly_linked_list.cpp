#include <iostream>
using namespace std;

class node
{
    public:
        int data;
        node *prev;
        node *next;
};

void traversal(node* head)
{
    node *p = head;

    while(p->next != NULL)
    {
        cout<<p->data<<endl;
        p = p->next;
    }
    cout<<p->data<<endl;
    cout<<endl;
    
    while(p->prev != NULL)
    {
        cout<<p->data<<endl;
        p = p->prev;
    }
    cout<<p->data<<endl;
    cout<<endl;
}

int main()
{
    node *n1 = new node();
    node *n2 = new node();
    node *n3 = new node();
    node *n4 = new node();

    n1->data = 21;
    n1->next = n2;
    n1->prev = NULL;

    n2->data = 45;
    n2->next = n3;
    n2->prev = n1;

    n3->data = 78;
    n3->next = n4;
    n3->prev = n2;

    n4->data = 92;
    n4->next = NULL;
    n4->prev = n3;

    traversal(n1);

    return 0;
}