#include <iostream>
using namespace std;

class node
{
    public:
        int data;
        node *next;
};

void traversal(node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element : " << ptr->data << endl;
        ptr = ptr->next; // we are updating the pointer to the next object.
    }
    cout << endl;
}

int isempty(node* top)
{
    if(top == NULL)
    {
        return 1;
    }
    return 0;
}

int isfull(node* top)
{
    node *p = new node ();
    if(p == NULL)
    {
        return 1;
    }
    return 0;
}

node *push(node* top, int element)
{
    if(isfull(top))
    {
        cout<<"stack overflow"<<endl;
    }
    else
    {
        node *ptr = new node ();
        ptr->next = top;
        ptr->data = element;
        return ptr;
    }
}

int pop(node **top)
{
    if(isempty(*top))
    {
        cout<<"Stack underflow"<<endl;
    }
    else
    {
        node *p = *top;
        int element = (*top)->data;
        *top = (*top)->next;
        delete(p);
        return element;
    }
}


int main()
{
    node *top = NULL;
    top = push(top, 89);
    top = push(top, 43);
    top = push(top, 37);
    top = push(top, 62);
    top = push(top, 12);
    top = push(top, 90);
    traversal(top);

    for (int i = 1; i <= 3; i++)
    {
        cout<<"The popped element is : "<<pop(&top)<<endl;
    }
    traversal(top);
    
    return 0;
}