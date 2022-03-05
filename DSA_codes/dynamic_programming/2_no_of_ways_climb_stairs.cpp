#include <bits/stdc++.h>
using namespace std;

/*reccursion*/

int climb(int n)
{
    if(n == 0) return 1;
    if(n == 1) return 1;

    int l = climb(n-1);
    int r = climb(n-2);

    return (l+r);
}
// same as fibonacci

int main()
{
    int n;
    cin>>n;
    cout<<climb(n);
    return 0;
}