#include <bits/stdc++.h>
using namespace std;

// memoization
int solve(int i, int tran, vector<int>& prices, int n, int k, vector<vector<int>> &dp) // using 36th 2nd approach
{
    if(i == n || tran == 2*k) return 0;

    if(dp[i][tran] != -1) return dp[i][tran];

    if(tran % 2 == 0)
    {
        int b = -prices[i] + solve(i+1, tran+1, prices, n, k, dp);
        int nb = 0 + solve(i+1, tran, prices, n, k, dp);
        return dp[i][tran] = max(b, nb);
    }
    else
    {
        int s = prices[i] + solve(i+1, tran+1, prices, n, k, dp);
        int ns = 0 + solve(i+1, tran, prices, n, k, dp);
        return dp[i][tran] = max(s, ns);
    }
}

int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<vector<int>> dp(n, vector<int>(2*k, -1));
    return solve(0, 0, prices, n, k, dp);
}

// tabulation
int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));

    for (int i = n-1; i >= 0; i--)
    {
        for (int tran = 2*k-1; tran >= 0 ; tran--)
        {
            if(tran % 2 == 0)
            {
                int b = -prices[i] + dp[i+1][tran+1];
                int nb = 0 + dp[i+1][tran];
                dp[i][tran] = max(b, nb);
            }
            else
            {
                int s = prices[i] + dp[i+1][tran+1];
                int ns = 0 + dp[i+1][tran];
                dp[i][tran] = max(s, ns);
            }
        }
    }
    
    return dp[0][0];
}   

// tabulation with space optimization
int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<int> after(2*k+1, 0), curr(2*k+1, 0);

    for (int i = n-1; i >= 0; i--)
    {
        for (int tran = 2*k-1; tran >= 0 ; tran--)
        {
            if(tran % 2 == 0)
            {
                int b = -prices[i] + after[tran+1];
                int nb = 0 + after[tran];
                curr[tran] = max(b, nb);
            }
            else
            {
                int s = prices[i] + after[tran+1];
                int ns = 0 + after[tran];
                curr[tran] = max(s, ns);
            }
        }
        after = curr;
    }
    
    return after[0];
}

// tabulation with 1-d array space optimization
int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<int> after(2*k+1, 0);

    for (int i = n-1; i >= 0; i--)
    {
        for (int tran = 2*k-1; tran >= 0 ; tran--)
        {
            if(tran % 2 == 0)
            {
                int b = -prices[i] + after[tran+1];
                int nb = 0 + after[tran];
                after[tran] = max(b, nb);
            }
            else
            {
                int s = prices[i] + after[tran+1];
                int ns = 0 + after[tran];
                after[tran] = max(s, ns);
            }
        }
    }
    
    return after[0];
}


int main()
{
    
    return 0;
}