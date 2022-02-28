#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
    long long sum=0, m = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
        if(m<sum)
        {
            m=sum;
        }
        if(sum <0)
        {
            sum =0;
        }
    }
    
    return m;
    
}    

int main()
{
    int arr[] = {4,-8,3};
    int n = sizeof(arr)/sizeof(int);
    cout<<maxSubarraySum(arr, n);
    return 0;
}