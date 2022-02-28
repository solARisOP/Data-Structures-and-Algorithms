#include <iostream>
using namespace std;

class node
{
    public:
        int data;
        node *next;
};

node *top = NULL; // making global variable so everyone can access it without passing it and change it without any problem.

void traversal(node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element : " << ptr->data << endl;
        ptr = ptr->next; // we are updating the pointer to the next object.
    }
    cout << endl;
}

int isempty()
{
    if(top == NULL)
    {
        return 1;
    }
    return 0;
}

int isfull()
{
    node *p = new node ();
    if(p == NULL)
    {
        return 1;
    }
    return 0;
}

node *push(int element)
{
    if(isfull())
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

int pop()
{
    if(isempty())
    {
        cout<<"Stack underflow"<<endl;
    }
    else
    {
        node *p = top;
        int element = top->data;
        top = top->next;
        delete(p);
        return element;
    }
}


int main()
{
    
    top = push(89);
    top = push(43);
    top = push(37);
    top = push(62);
    top = push(12);
    top = push(90);
    traversal(top);

    for (int i = 1; i <= 3; i++)
    {
        cout<<"The popped element is : "<<pop()<<endl;
    }

    traversal(top);
    
    return 0;
}