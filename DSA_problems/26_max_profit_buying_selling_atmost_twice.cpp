#include <bits/stdc++.h>
using namespace std;

int maxprofit(int arr[], int n)
{
    unordered_map<int,int> m;
    int k = INT_MAX, profit =0;
    int i=0;
    for (i; i < n; i++)
    {
        if(arr[i]<k)
        {
            if(profit!=0) break;
            k = arr[i];
        }
        if(arr[i]>n)
        {
            if(profit<(arr[i] -k))
            {
                profit = arr[i] -k;
                m[profit] = i;
            }
        }
    }
    int t = profit;
    profit = 0;
    k = INT_MAX;
    cout<<t<<endl;
    for (int j = m[t]+1; j < n; j++)
    {
        if(arr[j]<k)
        {
            k = arr[j];
        }
        if(arr[j]>k)
        {
            if(profit<(arr[j] -k))
            {
                profit = arr[j] -k;
            }
        }
    }
    return (profit +t);
    
}
int main()
{
    int arr[] = {3, 3, 5, 0, 0, 3, 1, 4} ;
    cout<<maxprofit(arr, sizeof(arr)/sizeof(int));
    return 0;
}