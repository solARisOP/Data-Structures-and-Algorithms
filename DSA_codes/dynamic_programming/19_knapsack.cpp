#include <bits/stdc++.h>
using namespace std;

// memoization
int solve(int i, int w, vector<int> weight, vector<int> value, vector<vector<int>> &dp)
{
    if(i == 0)
    {
        if(weight[0]<=w) return value[0];
        else return 0;
    }

    if(dp[i][w] != -1) return dp[i][w];
    int pick = -1e9, n_pick = 0;
    n_pick = 0 + solve(i-1, w, weight, value, dp);
    if(weight[i]<=w) pick = value[i] + solve(i-1, w - weight[i], weight, value, dp);

    
    return dp[i][w] = max(pick, n_pick);

}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
	return solve(n-1, maxWeight, weight, value, dp);
}

// tabulation
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));
    for (int wt = weight[0]; wt <= maxWeight; wt++)
    {
        dp[0][wt] = value[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int wt = 0; wt <= maxWeight; wt++)
        {
            int pick = -1e9, n_pick = 0;
            n_pick = 0 + dp[i-1][wt];
            if(weight[i]<=wt) pick = value[i] + dp[i-1][wt - weight[i]];
            dp[i][wt] = max(pick, n_pick);
        }
        
    }
    
    return dp[n-1][maxWeight];
}

// tabulation with space optimization
int knapsack_tab(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<int> prev(maxWeight+1, 0), curr(maxWeight+1, 0);
    for (int wt = weight[0]; wt <= maxWeight; wt++)
    {
        prev[wt] = value[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int wt = 0; wt <= maxWeight; wt++)
        {
            int pick = -1e9, n_pick = 0;
            n_pick = 0 + prev[wt];
            if(weight[i]<=wt) pick = value[i] + prev[wt - weight[i]];
            curr[wt] = max(pick, n_pick);
        }
        prev = curr;
    }
    
    return prev[maxWeight];
}

// tabulation with 1d array space optimization
int knapsack_tab1(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<int> prev(maxWeight+1, 0);
    for (int wt = weight[0]; wt <= maxWeight; wt++)
    {
        prev[wt] = value[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int wt = maxWeight; wt >= 0; wt--) // because left to right will be not possible that's why right to left.
        {
            int pick = -1e9, n_pick = 0;
            n_pick = 0 + prev[wt];
            if(weight[i]<=wt) pick = value[i] + prev[wt - weight[i]];
            prev[wt] = max(pick, n_pick);
        }
    }
    
    return prev[maxWeight];
}

int main()
{
    
    return 0;
}