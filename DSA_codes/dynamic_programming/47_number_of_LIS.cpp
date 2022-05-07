#include <bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 1), cnt(n, 1);
    int maxi =1;
    for (int i = 0; i < n ; i++)
    {
        for (int prev = 0; prev <= i-1; prev++) 
        {
            if(arr[prev]<arr[i] && dp[prev]+1 > dp[i]) // if length is greater that means we need to inherite the count in simple terms copy
            {
                dp[i] = dp[prev]+1;
                cnt[i] = cnt[prev];
            }
            else if(arr[prev]<arr[i] && dp[prev]+1 == dp[i]) // if length is equal that means we need to update the count as there is also a same length lis with different elements
            {
                cnt[i] += cnt[prev];
            }
        }
		maxi = max(dp[i], maxi);
    }
    for (auto i : cnt)
    {
        cout<<i<<" ";
    }
    
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        if(dp[i] == maxi) r+=cnt[i]; // the we are adding all total no. of lis
    }
    
    return r;
}

int main()
{
    
    return 0;
}