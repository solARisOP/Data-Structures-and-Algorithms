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
int main()
{
    // stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = new int [s.size];

    stack *s = new stack();
    s->size = 80;
    s->top = -1;
    s->arr = new int [s->size];

    s->arr[0] = 1;
    s->top++;
    if(isempty(s))
    {
        cout<<"The stack is empty"<<endl;
    }
    else
    {
        cout<<"The stack is not vempty"<<endl;
    }
    return 0;
}