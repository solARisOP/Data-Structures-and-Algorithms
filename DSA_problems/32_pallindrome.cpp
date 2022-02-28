#include <bits/stdc++.h>
using namespace std;

int palin(int n)
{
    int i=0, b[10];
    while(n!=0)
    {
        b[i] = n%10;
        n = n/10;
        i++;
    }
    int a[10];
    for(int j =0; j<i; j++)
    {
        a[j]= b[j];
    }
    for(int j =0; j<i/2; j++)
    {
        swap(b[j], b[i-1-j]);
    }
    for(int j =0; j<i; j++)
    {
        if(a[j] != b[j])
        {
            return 0;
        }
    }
    return 1;
}

int PalinArray(int a[], int n)
{
    for(int i=0; i<n; i++)
    {
        if(!palin(a[i]))
        {
            return 0;
        }
    }
    return 1;    
}

int main()
{
    int arr[] = {111, 222, 333, 444, 555};
    int n = sizeof(arr)/sizeof(int);
    cout<<PalinArray(arr,n);
    // cout<<palin(10);
    
    return 0;
}