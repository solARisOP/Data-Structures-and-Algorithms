#include <bits/stdc++.h>
using namespace std;

int result = INT_MAX;

int func(int i, int td, int n, int t[], int c[], vector<vector<int>> &dp, int maxi)
{
    if(i>=n)
    {
        result = min(result, maxi);
        return 0;
    }    
    
    if(dp[i][td] != -1) return dp[i][td];
    
    int m = INT_MAX;
    for(int j = 0; j<=td && t[i]>=j; j++)
    {
        int prev = maxi;
        int tab = (c[i]*(t[i]-j));
        maxi = max(tab, maxi);
        m = min(m,(tab+func(i+1, td -j, n, t, c, dp, maxi)));
        maxi = prev;
    }

    return dp[i][td] = m;
}

void min_choc(int td, int n, int t[], int c[])
{
    vector<vector<int>> dp(n,vector<int>(td+1, -1));
    func(0,td,n,t,c,dp, -1e9);
    cout<<result;
}

int main()
{
    int td, n;
    cin>>n>>td;
    int t[n], c[n];
    for(int &i : t) cin>>i;
    for(int &i : c) cin>>i;
    min_choc(td,n,t,c);
    return 0;
}