#include <bits/stdc++.h>
using namespace std;

int minSwap(int arr[], int n, int k)
{
    int i = 0, c=0;
    while(i<n)
    {
        if(arr[i]<=k)
        {
            c++;
        }
        i++;
    }
    if(c==n) return 0;
    int p=0;
    int j=0;
    for (j; j < c; j++)
    {
        if(arr[j]>k)
        {
            p++;
        }
    }
    int a =p;
    j=c;
    i=0;
    while(j<n)
    {
        if(arr[i]>k)
        {
            p--;
        }
        if(arr[j]>k)
        {
            p++;
        }
        a = min(p,a);
        i++;j++;
    }
    return a;
}
int main()
{
    int arr[] = {2, 7, 9, 5, 8, 7, 4};
    int n = sizeof(arr)/sizeof(int);
    cout<<minSwap(arr,n,6); 
    return 0;
}
