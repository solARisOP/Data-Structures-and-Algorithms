#include <bits/stdc++.h>
using namespace std;

int rollnum(int regNo)
{
    if(regNo/10 == 0) return regNo;
    int a[10], i=0;
    while(regNo != 0)
    {
        a[i] = regNo%10;
        regNo/=10;
        i++;
    }
    for (int j = 0; j < i/2; j++)
    {
        swap(a[j], a[i-j-1]);
    }
    int q = (i%2 == 0) ? i/2 : (i/2)+1;
    int j =0, t=0;
    while(j<i)
    {
        if(j == i-1)
        {
            regNo += a[j]*(pow(10, (q-t-1)));
            break;
        } 
        regNo += max(a[j], a[j+1])*(pow(10, (q-t-1)));
        j+=2;
        t++;
    }
    return regNo;
}

int main()
{
    int n;
    cin>>n;
    cout<<rollnum(n);
    return 0;
}