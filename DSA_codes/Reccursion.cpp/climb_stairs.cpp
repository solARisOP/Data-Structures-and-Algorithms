#include <iostream>
using namespace std;

int countways(int n)
{
    if(n < 0)
    {
        return 0;
    }
    if(n == 0)
    {
        return 1;
    }

    return countways(n-1) + countways(n-2);
}

int main()
{
    int a;
    cin>>a;
    int ans = countways(a);
    cout<<ans<<endl;
    return 0;
}