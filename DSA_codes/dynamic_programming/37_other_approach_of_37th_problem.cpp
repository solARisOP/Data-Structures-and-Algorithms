#include <bits/stdc++.h>
using namespace std;

// memoization
int solve(int i, int tran, vector<int>& prices, int n, vector<vector<int>> &dp)
{
    if(i == n || tran == 4) return 0;

    if(dp[i][tran] != -1) return dp[i][tran];

    if(tran % 2 == 0) // if tran is even means we can buy as shown in below function vector declaration
    {
        int b = -prices[i] + solve(i+1, tran+1, prices, n, dp); // because we have declared 2*2 vector, we have to increase the tran here as we are halfway through the transactions
        int nb = 0 + solve(i+1, tran, prices, n, dp);
        return dp[i][tran] = max(b, nb);
    }
    else // if odd we should sell
    {
        int s = prices[i] + solve(i+1, tran+1, prices, n, dp); // here transaction is completed so we need to increase the tran
        int ns = 0 + solve(i+1, tran, prices, n, dp);
        return dp[i][tran] = max(s, ns);
    }
}

int maxProfit(vector<int>& prices, int n)
{
    vector<vector<int>> dp(n, vector<int>(4, -1)); // 4 size array because there can be atmost 2 transactions so (buy, sell, buy, sell) = 4
    return solve(0, 0, prices, n, dp);
}

// tabulation
int maxProfit(vector<int>& prices, int n)
{
    vector<vector<int>> dp(n, vector<int>(4+1, 0));
    // base cases not needed coz of all are 0 initially
    for(int tran = 0; tran <= 4; tran++)
    {
        dp[n][tran] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][4] = 0;
    }

    for (int i = n-1; i >= 0; i--)
    {
        for (int tran = 3; tran >= 0; tran--)
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
int maxProfit(vector<int>& prices, int n)
{
    vector<int> after(4+1, 0), curr(4+1, 0);
    // base cases not needed coz of all are 0 initially
    for(int tran = 0; tran <= 4; tran++)
    {
        after[tran] = 0;
    }

    for (int i = n-1; i >= 0; i--)
    {
        curr[4] = 0; // because the base case is for every row
        for (int tran = 3; tran >= 0; tran--)
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
int maxProfit(vector<int>& prices, int n)
{
    vector<int> after(4+1, 0);
    // base cases not needed coz of all are 0 initially
    for(int tran = 0; tran <= 4; tran++)
    {
        after[tran] = 0;
    }

    for (int i = n-1; i >= 0; i--)
    {
        for (int tran = 3; tran >= 0; tran--)
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