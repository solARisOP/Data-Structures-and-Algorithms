#include <bits/stdc++.h>
using namespace std;

void printarray(int a[], int n)
{
    for(int i = 0; i<n; i++)
    {
        cout<<a[i]<<"   ";
    }
}

void rotate(int a[], int n)
{
    int t= a[n-1];
    for (int i = n; i > 0; i--)
    {
        a[i] = a[i-1]; 
    }
    a[0] = t;
    
}

int main()
{
    int arr[7] = {3, 4, 5, 6, 2, 1, 16};
    int n = sizeof(arr)/sizeof(int);
    rotate(arr, 7);
    printarray(arr,7);
    return 0;
}