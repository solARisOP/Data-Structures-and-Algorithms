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

int main()
{
    stack *sp = new stack ();
    sp->size = 10;
    sp->top = -1;
    sp->arr = new int [sp->size];

    cout<<"before pushing Full : "<<isfull(sp)<<endl;
    cout<<"before pushing Empty : "<<isempty(sp)<<endl;
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
    // push(sp, 66); //--> stack overflow no more items can be inserted
    cout<<"after pushing Full : "<<isfull(sp)<<endl;
    cout<<"after pushing Empty : "<<isempty(sp)<<endl;
    cout<<pop(sp)<<endl;
    cout<<pop(sp)<<endl;
    cout<<pop(sp)<<endl;
    cout<<pop(sp)<<endl;
    cout<<pop(sp)<<endl;
    cout<<pop(sp)<<endl;
    cout<<pop(sp)<<endl;
    cout<<pop(sp)<<endl;
    cout<<pop(sp)<<endl;
    cout<<pop(sp)<<endl;
    // cout<<pop(sp)<<endl; //--> stack underflow no more items are left for popping 
    cout<<"after popping Full : "<<isfull(sp)<<endl;
    cout<<"after popping Empty : "<<isempty(sp)<<endl;


    return 0;
}