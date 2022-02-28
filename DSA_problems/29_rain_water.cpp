#include <bits/stdc++.h>
using namespace std;



long long trappingWater(int arr[], int n)
{
    if(n<=2) return 0;
    // int g = maximum(arr, n);
    long long result =0;
    int l = 0, r = n-1;
    while(l<r)
    {
        while(arr[l]<=arr[l+1])
        {
            ++l;
        }
        while(arr[r]<= arr[r-1])
        {
            --r;
        }
        if((r-l)==1) return result;
        else if(r-l==2)
        {
            // int t = arr[l] - arr[l+1];
            if(arr[l]<arr[r])
            {
                result += arr[l]- arr[l+1];
                ++l;
            }       
            else
            {
                result += arr[r]-arr[r-1];
                --r;
            }        
            // arr[l] = arr[l-1];
        }
        else if(r-l>2)
        {
            if(arr[l]<arr[r])
            {
                result += arr[l]- arr[l+1];
                ++l;
                arr[l] = arr[l-1];
            }       
            else
            {
                result += arr[r]-arr[r-1];
                --r;
            }
        }
    }
    return result;
}

int main()
{
    int arr[] = {3,0,0,2,0,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<trappingWater(arr, n);
    // cout<<maximum(arr, n);
    return 0;
}