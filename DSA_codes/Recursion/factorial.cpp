#include <iostream>
using namespace std;

int fac(int n)
{
    // base condition
    if(n == 0)
    {
        return 1;
    }

    // recursive relation

    return n * fac(n-1);

    // it is a tail recursion.
}

int main()
{
    int a = 5;
    int ans = fac(a);
    cout<<ans<<endl;
    return 0;
}