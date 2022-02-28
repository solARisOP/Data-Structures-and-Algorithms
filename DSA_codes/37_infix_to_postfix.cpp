#include <iostream>
#include <string>
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

char stacktop()
{
    return chk->arr[chk->top];
}

int precedence(char c)
{
    if(c == '/' || c == '*')
    {
        return 3;
    }
    else if(c == '+' || c == '-')
    {
        return 2;
    }
    return 0;
}

int isoperator(char c)
{
    if(c == '+' || c == '-' || c == '/' || c == '*')
    {
        return 1;
    }
    return 0;
}

void infixtopostfix(char* infix)
{
    chk->size = 10;
    chk->top = -1;
    chk->arr = new char[chk->size]; 
    char*postfix = new char [100];
    int i = 0, j = 0;
    while(infix[i] != '\0')
    {
        if(!isoperator(infix[i]))
        {
            postfix[j] = infix[i];
            // postfix = postfix+infix[i];
            i++;
            j++;
        }
        else
        {
            if(precedence(infix[i]) > precedence(stacktop()))
            {
                push(infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop();
                j++;
            }
        }
    }
    while(!isempty())
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
    cout<<postfix;
}

int main()
{   
    char* infix;
    cout<<"Enter the expression : ";
    cin>>infix;
    infixtopostfix(infix);
    //cout<<ans;

    return 0;
}