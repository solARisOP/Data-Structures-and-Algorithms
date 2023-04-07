#include <bits/stdc++.h>
using namespace std;

// memoization
int solve(int i, int n, int wt, int weights[], int val[], vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (weights[i] <= wt)
            return val[0];
        return 0;
    }

    if (dp[i][wt] != -1)
        return dp[i][wt];

    int take = -1e9, n_take = 0;

    if (wt >= weights[i])
        take = val[i] + solve(i - 1, n, wt - weights[i], weights, val, dp);
    n_take = solve(i - 1, n, wt, weights, val, dp);

    return dp[i][wt] = max(n_take, take);
}
int knapSack(int W, int wt[], int val[], int n)
{
    // Your code here
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return solve(n - 1, n, W, wt, val, dp);
}

// tabulation
int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));
    
    for (int w = wt[0]; w <= W; w++)
    {
        dp[0][w] = val[0];
    }

    for(int i = 1; i<n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            int take = -1e9, n_take = 0;
            if (w >= wt[i]) take = val[i] + dp[i - 1][w - wt[i]];
            n_take = dp[i - 1][w];
            dp[i][w] = max(n_take, take);
        }
    }

    return dp[n - 1][W];
}



int main()
{

    return 0;
}

