#include <bits/stdc++.h>
using namespace std;

void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<"   ";
    }
    cout<<endl;
}

int pos(int a[], int n, int p)
{
    for (int i = p; i < n; i++)
    {
        if(a[i] >= 0) return i;
    }
    return -1;
}
int neg(int a[], int n, int p)
{
    for (int i = p; i < n; i++)
    {
        if(a[i] < 0) return i;
    }
    return -1;
}

void swaap_p(int arr[], int s, int e)
{
    int t =e;
    for (int i = e-1; i > s; i--)
    {
        if(arr[i]>=0)
        {
            swap(arr[i], arr[t]);
            t =i;
        }
    } 
}

void swaap_n(int arr[], int s, int e)
{
    int t =e;
    for (int i = e-1; i > s; i--)
    {
        if(arr[i]<0)
        {
            swap(arr[i], arr[t]);
            t =i;
        }
    }
}

void rearrange(int arr[], int n)
{
    if(n<=2) return;
    int i =0;
    while(i<n-2)
    {
        if(i == 0 )
        {
            if(neg(arr, n, i+1+1) == -1 && arr[i+1]>=0 && arr[i]<0)
            {
                swap(arr[i], arr[i+1]);
                return;
            }
            else if(pos(arr, n, i+1+1) == -1 && arr[i+1]<0 && arr[i]>=0)
            {
                swap(arr[i], arr[i+1]);
                return;
            } 
        }

        if(arr[i]>=0)
        {
            if(arr[i+1]>=0)
            {
                int f = neg(arr, n, i+1+1);
                if(f == -1) return;
                swap(arr[i+1], arr[f]);
                swaap_p(arr, i+1, f);
            }
        }
        else
        {
            if(arr[i+1]<0)
            {
                int g = pos(arr, n, i+1+1);
                if(g == -1) return;
                swap(arr[i+1], arr[g]);
                swaap_n(arr, i+1, g);
            } 
        }
        i++;
    }   
}

int main()
{
    int n;
    cin>>n;
    int arr[n] ;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    printarray(arr, n);
    cout<<endl;
    rearrange(arr,n);
    printarray(arr, n);
        
    return 0;
}