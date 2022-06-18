#include <iostream>
using namespace std;

int power(int a, int n)
{
    if(n == 0)
    {
        return 1;
    }

    return a * power(a, n-1);
}

int main()
{
    int a, n, ans;
    cin>>a>>n;

    ans = power(a, n);
    cout<<ans<<endl;


    return 0;
}