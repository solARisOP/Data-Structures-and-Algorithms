#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

int longestSubsequence(int n, int a[])
{
    // your code here
    vi dp(n, 1);
    int maxi= -1;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if(abs(a[i]-a[prev]) == 1) dp[i] = max(dp[i], 1+dp[prev]);
        }
        maxi = max(maxi, dp[i]);
    }
    
    return maxi;
}

int main()
{
    
    return 0;
}