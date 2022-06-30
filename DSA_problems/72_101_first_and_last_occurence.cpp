#include <bits/stdc++.h>
using namespace std;

vector<int> find(int arr[], int n , int x )
{
    vector<int> ans;
    auto it = lower_bound(arr, arr+n, x);
    if(it-arr != n && arr[it-arr] == x) ans.push_back(it-arr);
    else ans.push_back(-1);
    
    auto it2 = upper_bound(arr, arr+n, x);
    if(it2-arr != n && arr[it-arr] == x) ans.push_back(it2-arr-1);
    else if(it2-arr == n && arr[it2-arr-1] == x) ans.push_back(it2-arr-1);
    else ans.push_back(-1);
    
    return ans;
    
}

int main()
{
    int n, x;
    cin>>n>>x;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    for(auto it : find(arr, n, x)) cout<<it<<"  ";
    
    return 0;
    
}