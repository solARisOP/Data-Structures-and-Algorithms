#include <bits/stdc++.h>
using namespace std;

int match(char a, char b)
{
    if((a == '{' && b == '}') || (a == '[' && b == ']') || (a == '(' && b == ')'))
    {
        return 1;
    }
    return 0;
}

bool ispar(string x)
{
    if(x.size() <= 1) return false;
    int i =0;
    stack <char>s;
    while(i<x.size())
    {
        if(x[i] == '(' || x[i] == '[' || x[i] == '{')
        {
            s.push(x[i]);
            i++;
        }
        else if(x[i] == ')' || x[i] == ']' || x[i] == '}')
        {
            if(s.empty())
            {
                return false;
            }
            char b = s.top();
            if(match(b, x[i]))
            {
                s.pop();
                i++;
            }    
            else
            {
                return false;
            }
        }
    }
    if(!s.empty())
    {
        return false;
    }        
    return true;    
}

int main()
{
    string s="()";
    cout<<ispar(s);
    return 0;
}