#include <bits/stdc++.h>
using namespace std;

int encrypt (int data, int k)
{
    int i=0, a[10], b[10], q=0;
    while(data!=0)
    {
        a[i] = data%10; i++;
        data=data/10;
    }
    for (int j = 0; j < i/2; j++)
    {
        swap(a[j], a[i-1-j]);
    }
    for (int j = k; j < i; j++)
    {
        b[q] = a[j];q++;
    }
    for (int j = k-1; j >=0; j--)
    {
        swap(a[j], a[j+q]);
    }
    for (int j = 0; j < q; j++)
    {
        a[j] = b[j];
    }
    
    for (int j = 0; j < i; j++)
    {
        a[j] = a[j]*(pow(10, (i-j-1)));
    }
    
    return accumulate(a, a+i, 0);
     
}

int main()
{   int n, k;
    cin>>n>>k;
    // cout<<n<<endl;
    cout<<encrypt(n,k);
    return 0;
}