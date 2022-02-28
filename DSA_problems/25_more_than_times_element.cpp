#include <bits/stdc++.h>
using namespace std;

void nbyk_times(int arr[], int n, int k)
{
    if(k<2 || n==1) return;
    // arr[n] = INT_MIN;
    sort(arr, arr+n);
    int i=0, p=1;
    while(i<n)
    {
        // cout<<i<<endl;
        if(n/k < p)
        {
            int t= arr[i];
            cout<<arr[i]<<"   ";
            while(arr[i+1] == t)
            {
                i++;
                p++;
            }
            cout<<p;
            p=1;
            cout<<endl;
        } 
        else if(arr[i] == arr[i+1])
        {
            int t= arr[i];
            p++; 
        }
        else
        {
            p=1;
        }
        i++;
    }
}

int main()
{
    int arr[] = { 2, 3, 3, 2 };
    nbyk_times(arr, sizeof(arr)/sizeof(int), 3);
    return 0;
}