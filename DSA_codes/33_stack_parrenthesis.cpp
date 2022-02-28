#include <iostream>
using namespace std;

class stack
{
    public:
        char *arr;
        int size;
        int top;
};
stack *chk = new stack ();
    

int isempty()
{
    if(chk->top == -1)
    {
        return 1;
    }
    return 0;
}

int isfull()
{
    if(chk->top == chk->size-1)
    {
        return 1;
    }
    return 0;
}

void push(char c)
{
    if(isfull())
    {
        cout<<"Stack overflow"<<endl;
    }
    else
    {
        chk->top ++;
        chk->arr[chk->top] = c;
    }
}

char pop()
{
    if(isempty())
    {
        cout<<"stack underflow"<<endl;
        return -1;
    }
    else
    {
        char val = chk->arr[chk->top];
        chk->top--;
        return val;
    }
}

void parenthesis(char *exp)
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(')
        {
            push(exp[i]);

        }
        else if(exp[i] == ')')
        {
            if(isempty())
            {
                cout<<"Parenthesis not matching"<<endl;
                return;
            }
            pop();
            
        }
    }
    if(isempty())
    {
        cout<<"Parenthesis is matching"<<endl;
        return;
    }
    else
    {
        cout<<"Parenthesis not matching"<<endl;
        return;
    }
    
}


int main()
{
    chk->size = 100;
    chk->top = -1;
    chk->arr = new char[chk->size];    
    char *exp;

    cout<<"Enter the expression : ";
    cin>>exp;
    // cout<<endl;
    parenthesis(exp);

    return 0;
}