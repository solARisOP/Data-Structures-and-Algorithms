#include <iostream>
using namespace std;

class stack
{
    public:
        int size;
        int top;
        int *arr;
};

int isempty(stack *s)
{
    if(s->top == -1)
    {
        return 1;
    }
    return 0;
}

int isfull(stack *s)
{
    if(s->top == s->size-1)
    {
        return 1;
    }
    return 0;
}

void push(stack *sp, int element)
{
    if(isfull(sp))
    {
        cout<<"Stack overflow"<<endl;
    }
    else
    {
        sp->top ++;
        sp->arr[sp->top] = element;
    }
}

int pop(stack *sp)
{
    if(isempty(sp))
    {
        cout<<"stack underflow ";
        return -1;
        cout<<endl;
    }
    else
    {
        int val = sp->arr[sp->top];
        sp->top--;
        return val;
    }
}

int peek(stack *sp, int i)
{
    int ind = sp->top-i+1;
    if(ind<0)
    {
        cout<<"not a valid position for the stack"<<endl;
        return -1;
    }
    return sp->arr[ind];

}

int main()
{
    stack *sp = new stack ();
    sp->size = 100;
    sp->top = -1;
    sp->arr = new int [sp->size];


    push(sp, 3);
    push(sp, 5);
    push(sp, 78);
    push(sp, 45);
    push(sp, 39);
    push(sp, 15);
    push(sp, 23);
    push(sp, 56);
    push(sp, 32);
    push(sp, 45);

    for (int i = 1; i <= sp->top + 1; i++)
    {
        cout<<"the value at index "<<i<<" is "<<peek(sp, i)<<endl;
        cout<<endl;
    }

    return 0;
}