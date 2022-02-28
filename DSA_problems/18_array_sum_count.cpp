#include <bits/stdc++.h>
using namespace std;

// int getPairsCount(int arr[], int n, int k)
// {
//     sort(arr, arr+n);
//     int t = INT_MIN;
//     int j=0, i=j+1, c=0;
//     while(j<n-1)
//     {
//         if(i >= n) 
//         {
//             ++j;
//             i = j+1;
//         }    
//         t = arr[j];
//         if(t+arr[i++] == k)
//         {
//            ++c;
//         }        
//     }
//     return c;
// }
int getPairsCount(int arr[], int n, int k)
{
    int c=0;
    unordered_map<int,int>m;
    for (int i = 0; i < n; i++)
    {
        int s  = k - arr[i];
        if(m[s])
        {
            c+=m[s];
        }
        m[arr[i]]++;
    }
    return c;
}

int main()
{
    int a[] = {1,1,1,1};
    int n = sizeof(a)/sizeof(int);
    int k;
    cin>>k;
    cout<<getPairsCount(a, n, k);
    return 0;
}