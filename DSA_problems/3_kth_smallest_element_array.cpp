#include <bits/stdc++.h>
using namespace std;

void printarray(int a[], int n)
{
    for(int i = 0; i<n; i++)
    {
        cout<<a[i]<<"   ";
    }
}

int kthSmallest(int a[], int l, int r, int k)
{
    sort(a, a+r+1);
    int i = 0, j=1;
    if(k==1) return a[0];
    while(i<=r)
    {
        if(a[i] == a[i+1])
        {
            i++;
        }
        else
        {
            i++;
            j++;
            if(j==k)
            {
                return a[i];
            }
        }
    }
    return a[i-1];      
}

int main()
{
    int a[] = {2,2,3,4,5,1,1,1,5};
    int n = sizeof(a)/sizeof(int);
    cout<<kthSmallest(a, 0, n-1, 5)<<endl;;
    printarray(a, n);
    return 0;
}