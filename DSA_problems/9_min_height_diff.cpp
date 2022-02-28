#include <bits/stdc++.h>
using namespace std;

void printarray(int a[], int n)
{
    for(int i = 0; i<n; i++)
    {
        cout<<a[i]<<"   ";
    }
}

    int getMinDiff(int arr[], int n, int k) {
        for(int i=0; i<n; i++)
        {
            // cout<<"for "<<arr[i]<<"   ";
            int temp = arr[i];
            arr[i]-=k; temp+=k;
            if(arr[i]<0)
            {
                arr[i]+=(2*k);
                // cout<<arr[i]<<"   ";
                continue;
            }
            cout<<endl; 
            if(arr[i]<temp)
            {
                arr[i];
                // cout<<arr[i]<<"   ";
            }
            else
            {
                arr[i] = temp;
                // cout<<arr[i]<<"   ";
            }
            
        }
        sort(arr, arr+n);
        return (arr[n-1] - arr[0]);
    }

int main()
{
    int a[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
    int m = sizeof(a)/sizeof(int);
    cout<<getMinDiff(a,m,5)<<endl;
    printarray(a,30);
    return 0;
}