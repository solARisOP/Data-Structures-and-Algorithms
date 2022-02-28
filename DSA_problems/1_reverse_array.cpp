#include <bits/stdc++.h>
using namespace std;

void printarray(int a[], int n)
{
    for(int i = 0; i<n; i++)
    {
        cout<<a[i]<<"   ";
    }
}

void reverse(int a[], int n)
{
    for(int i=0; i<n/2; i++)
    {
        swap(a[i], a[n-1-i]);
    }
}


int main()
{
    int a[] = {3,4,1,5,4,5,2};
    int n = sizeof(a)/sizeof(int);
    reverse(a, n);
    printarray(a, n);
    return 0;
}