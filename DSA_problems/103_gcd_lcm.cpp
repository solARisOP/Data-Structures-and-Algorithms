#include <bits/stdc++.h>

using namespace std;

int func(int a, int b)
{
    if(a == 0) return b;
    if(b == 0) return a;
    if(a == b) return a;

    int div = (a<b)?a:b;
    int divd = (a>b)?a:b;
    int rem = 1;

    while(rem)
    {
        rem = divd%div;
        divd = div;
        div = rem;
    }

    return (a*b)/divd;
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<func(a,b);
    return 0;
}