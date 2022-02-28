#include <bits/stdc++.h>
using namespace std;

void printarray(int a[], int n)
{
    for(int i = 0; i<n; i++)
    {
        cout<<a[i]<<"   ";
    }
}

void negative (int a[], int n)
{
    if(n==1) return;
    int i=0, j=n-1;
    while(i<j)
    {
        while(a[i]<0)
        {
            i++;
        }
        while(a[j]>=0)
        {
            j--;
        }
        if(i<j)
        {
            swap(a[i], a[j]);
        }
    }
}

int main()
{
    int a[]= {-4,-3,5,1,78,-3,54,-2};
    int n = sizeof(a)/sizeof(int);
    negative(a,n);
    printarray(a,n);
    return 0;
}