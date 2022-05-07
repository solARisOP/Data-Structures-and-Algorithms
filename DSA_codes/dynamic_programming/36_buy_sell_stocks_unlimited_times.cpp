#include <bits/stdc++.h>
using namespace std;

// memoization
long solve(int i, int buy, long *values, int n, vector<vector<long>> &dp)
{
    if(i == n) return 0;

    if(dp[i][buy] != -1) return dp[i][buy];

    if(buy == 1) // means we can buy the stock
    {
        long take = -values[i] + solve(i+1, 0, values, n, dp); // if we buy the stock
        long n_take = 0 + solve(i+1, 1, values, n, dp); // if we dont buy the stock
        return dp[i][buy] = max(take, n_take); // the maax profit we get
    }
    else // we cannot buy the stock
    {
        long take = values[i] + solve(i+1, 1, values, n, dp); // if we sell the stock 
        long n_take = 0 + solve(i+1, 0, values, n, dp); // if we dont sell the stock
        return dp[i][buy] = max(take, n_take); // the max profit we get
    }
}

long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n, vector<long>(2, -1)); // because we have only 2 options if we can buy or cannot thats why we took 2.
    return solve(0, 1, values, n, dp);
}

// tabulation 
long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n+1, vector<long>(2, 0));
    dp[n][0] = dp[n][1] = 0;

    for (int i = n-1; i >= 0; i--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            if(buy == 1) 
            {
                long take = -values[i] + dp[i+1][0]; 
                long n_take = 0 + dp[i+1][1]; 
                dp[i][buy] = max(take, n_take);
            }
            else 
            {
                long take = values[i] + dp[i+1][1]; 
                long n_take = 0 + dp[i+1][0]; 
                dp[i][buy] = max(take, n_take); 
            }
        }
    }

    return dp[0][1];
}

// tabulation with space optimization
long getMaximumProfit(long *values, int n)
{
   vector<long> ahead(2, 0), curr(2,0);
    ahead[0] = ahead[1] = 0;

    for (int i = n-1; i >= 0; i--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            if(buy == 1) 
            {
                long take = -values[i] + ahead[0]; 
                long n_take = 0 + ahead[1]; 
                curr[buy] = max(take, n_take);
            }
            else 
            {
                long take = values[i] + ahead[1]; 
                long n_take = 0 + ahead[0]; 
                curr[buy] = max(take, n_take); 
            }
        }
        ahead = curr;
    }

    return ahead[1];
}

// tabulation with variable space optimization
long getMaximumProfit(long *values, int n)
{
    long aheadbuy, aheadnotbuy, currbuy, currnotbuy;
    aheadnotbuy = aheadbuy = 0;

    for (int i = n-1; i >= 0; i--)
    { 
        currbuy = max(-values[i] + aheadnotbuy, 0 + aheadbuy);
        currnotbuy = max(values[i] + aheadbuy, 0 + aheadnotbuy); 

        aheadbuy = currbuy;
        aheadnotbuy = currnotbuy;
    }

    return aheadbuy;
}

int main()
{
    
    return 0;
}