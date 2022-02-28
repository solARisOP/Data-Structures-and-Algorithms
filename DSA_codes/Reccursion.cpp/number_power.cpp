#include <iostream>
using namespace std;

long long int power(int a, int b)
{
    cout<<"a :"<<a<<"   "<<"b :"<<b<<endl;
    if(b == 0)
    {
        return 1;
    }
    if(b == 1)
    {
        return a;
    }
    long long int x = power(a, b/2);

    if(b%2 == 0)
    {
        return x * x;
    }
    else
    {
        return a * x * x;
    }
}

int main()
{
    int a, b;
    cin>>a>>b;
    cout<<power(a,b)<<endl;
    return 0;
}