#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

void transversal(node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element : " << ptr->data << endl;
        ptr = ptr->next; // we are updating the pointer to the next object.
    }
    cout << endl;
}

node *deleteatbegin(node *head)
{
    node *p = head;
    head = head->next;
    delete (p);
    return head;
}

node *deleteatindex(node *head, int index)
{
    node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    node *ptr = p->next;
    p->next = ptr->next;
    delete (ptr);

    return head;
}

node *deleteatend(node *head)
{
    node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }

    node *q = head;
    while ((q->next)->next != NULL)
    {
        q = q->next;
    }

    q->next = NULL; // q->next = p->next both are same.
    delete (p);
    return head;
}

node *deletevaluenode(node *head, int element)
{
    node *p = head;
    node *q = head;

    while (q->data != element && q->next != NULL)// if the value is not in the linked list
    {
        q = q->next;
    }

    while (p->next != q)
    {
        p = p->next;
    }

    if(q->data == element)
    {
        p->next = q->next;
        delete (q);
    }

    return head;
}

int main()
{
    node *head = new node();
    node *rao = new node();
    node *shrey = new node();
    node *gopu = new node();
    node *abhi = new node();

    head->data = 54;
    head->next = rao;

    rao->data = 66;
    rao->next = shrey;

    shrey->data = 78;
    shrey->next = gopu;

    gopu->data = 83;
    gopu->next = abhi;

    abhi->data = 91;
    abhi->next = NULL;

    transversal(head);

    // head = deleteatbegin(head);
    // head = deleteatindex(head, 3);
    // head = deleteatend(head);
    head = deletevaluenode(head, 3);
    transversal(head);

    return 0;
}