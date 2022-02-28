#include <bits/stdc++.h>
using namespace std;

void printarray(int a[], int n)
{
    for(int i = 0; i<n; i++)
    {
        cout<<a[i]<<"   ";
    }
}


void sort012(int a[], int n)
{
    int c0=0, c1 =0, c2 =0;
    for (int i = 0; i < n; i++)
    {
        if(a[i] == 0)
        {
            c0++;
        }
        if(a[i] == 1)
        {
            c1++;
        }
        if(a[i] == 2)
        {
            c2++;
        }
    }
    int i=0;
    while(c0 >0)
    {
        a[i] = 0; i++;
        c0--;
    }
    while(c1 >0)
    {
        a[i] = 1; i++;
        c1--;
    }
    while(c2 >0)
    {
        a[i] = 2; i++;
        c2--;
    }
}

int main()
{
    int arr[] = {0,2,0,0,1,2,1};
    int n = sizeof(arr)/sizeof(int);
    sort012(arr, n);
    printarray(arr, n);
    return 0;
}