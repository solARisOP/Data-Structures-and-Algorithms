#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int &i : arr)cin>>i;
    
    if(n<=k) cout<<n;
    else cout<<k+1;

    return 0;
}