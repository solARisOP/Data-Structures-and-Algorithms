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
        return  1;
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
        cout<<"stack  overflow"<<endl;
    }
    else
    {
        chk->top++;
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
    
    char val = chk->arr[chk->top];
    chk->top--;
    return val;
}

int match(char a, char b)
{
    if((a == '{' && b == '}') || (a == '[' && b == ']') || (a == '(' && b == ')'))
    {
        return 1;
    }
    return 0;
}

void parenthesis(char *exp)
{
    chk->size = 100;
    chk->top = -1;
    chk->arr = new char[chk->size];
    char p_ch;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(isempty())
            {
                cout<<"Parenthesis not matching"<<endl;
                return;
            }
            p_ch = pop();
            if(!match(p_ch, exp[i]))
            {
                cout<<"Parenthesis not matching"<<endl;
                return;
            }

        }
    }
    if(isempty())
    {
        cout<<"Parenthesis matching"<<endl;
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
    
    char *exp;

    cout<<"Enter the expression : ";
    cin>>exp;
    parenthesis(exp);    
    
    return 0;
}