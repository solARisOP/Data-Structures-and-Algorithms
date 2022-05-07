#include <bits/stdc++.h>
using namespace std;

// memoization
int solve(int i, int buy, int fee, vector<int> &prices, int n, vector<vector<int>> &dp) // sol. taken from dp 35 with a slight change of deducting the fees
{
    if(i == n) return 0;

    if(dp[i][buy] != -1) return dp[i][buy];

    if(buy == 1)
    {
        int take = -prices[i] + solve(i+1, 0, fee, prices, n, dp);
        int n_take = 0 + solve(i+1, 1, fee, prices, n, dp);
        return dp[i][buy] = max(take, n_take);
    }
    else
    {
        int take = prices[i] + solve(i+1, 1, fee, prices, n, dp) - fee;
        int n_take = 0 + solve(i+1, 0, fee, prices, n, dp);
        return dp[i][buy] = max(take, n_take);
    }
}

int maximumProfit(int n, int fee, vector<int> &prices) 
{
    vector<vector<int>> dp(n, vector<int>(2, -1)); 
    return solve(0, 1, fee, prices, n, dp);
}

int main()
{
    
    return 0;
}