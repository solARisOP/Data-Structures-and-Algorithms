#include <bits/stdc++.h>
using namespace std;

pair<int, int> max_min(int a[], int n)
{
    pair<int, int> p;
    int l = INT_MIN, s = INT_MAX;
    for(int i =0; i<=n/2; i++)
    {
        if(a[i]>a[n-1-i])
        {
            if(a[i]>l)
            {
                l=a[i];
            }
        }
        else
        {
            if(a[n-1-i]>l)
            {
                l = a[n-1-i];
            }
        }
    }
    p.first = l;
    for(int i =0; i<=n/2; i++)
    {
        if(a[i]<a[n-1-i])
        {
            if(a[i]<s)
            {
                s=a[i];
            }
        }    
        else
        {
            if(a[n-1-i]<s)
            {
                s = a[n-1-i];
            }
        }
    }
    p.second = s;
    return p;
}

int main()
{
    int a[] = {45, 78, 3, 56, 2, 7, 135, 34, 22, 7, 19};
    int n = sizeof(a)/sizeof(int);
    pair<int, int>p = max_min(a, n);
    cout<<p.first<<"    "<<p.second<<endl;
    return 0;
}