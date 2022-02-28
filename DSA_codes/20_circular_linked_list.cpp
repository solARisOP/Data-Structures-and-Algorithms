#include <iostream>
using namespace std;

class node
{
    public:
        int data;
        node *next;
};

void traversal(node *head)
{
    node *p = head;
    do
    {
        cout << "element : " << p->data << endl;
        p = p->next;
    } while (p != head);
}

node *empty(node *head, int element)
{
    if (head == NULL)
    {
        head = new node();
        head->data = element;
        head->next = NULL;
        return head;
    }

    else
    {
        node *ptr = new node();
        ptr->data = element;
        head->next = ptr;
        ptr->next = head;
        return head;
    }
}

node *insertnode(node *head, int element)
{
    if (head == NULL || head->next == NULL)
    {
        head = empty(head, element);
        return head;
    }

    else
    {
        node *ptr = new node();
        node *p = head->next;

        while (p->next != head)
        {
            p = p->next;
        }
        ptr->data = element;
        p->next = ptr;
        ptr->next = head;

        return ptr;
    }    
}

int main()
{
    node *head = NULL;

    head = insertnode(head, 98);
    head = insertnode(head, 56);
    head = insertnode(head, 23);
    head = insertnode(head, 11);

    traversal(head);

    return 0;
}