#include <bits/stdc++.h>
using namespace std;

// memoization
int solve(int i, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
{
    if(i == 0) return (w/weight[0])*profit[0]; // because it has an infinite supply

    if(dp[i][w] != -1) return dp[i][w];

    int pick = 0;
    int n_pick = 0 + solve(i-1, w, profit, weight, dp);
    if(weight[i] <= w) pick = profit[i] + solve(i, w-weight[i], profit, weight, dp); 

    return dp[i][w] = max(pick, n_pick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w+1, -1));
    return solve(n-1, w, profit, weight, dp);
}

// tabulation
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w+1, 0));
    for (int wt = 0; wt <= w; wt++)
    {
        dp[0][wt] = (wt/weight[0])*profit[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int wt = 0; wt <= w; wt++)
        {
            int pick = 0;
            int n_pick = 0 + dp[i-1][wt];
            if(weight[i] <= wt) pick = profit[i] + dp[i][wt-weight[i]]; 

            dp[i][wt] = max(pick, n_pick);
        }
    }
    
    return dp[n-1][w];
}

// tabulation with space optimization
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int> prev(w+1, 0), curr(w+1, 0);
    for (int wt = 0; wt <= w; wt++)
    {
        prev[wt] = (wt/weight[0])*profit[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int wt = 0; wt <= w; wt++)
        {
            int pick = 0;
            int n_pick = 0 + prev[wt];
            if(weight[i] <= wt) pick = profit[i] + curr[wt-weight[i]]; 

            curr[wt] = max(pick, n_pick);
        }
        prev = curr;
    }
    
    return prev[w];
}

// tabulation with 1-d array space optimization
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int> prev(w+1, 0);
    for (int wt = 0; wt <= w; wt++)
    {
        prev[wt] = (wt/weight[0])*profit[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int wt = 0; wt <= w; wt++)
        {
            int pick = 0;
            int n_pick = 0 + prev[wt];
            if(weight[i] <= wt) pick = profit[i] + prev[wt-weight[i]]; 

            prev[wt] = max(pick, n_pick); // re-writting the element so we can use it to compute further elements
        }
    }
    
    return prev[w];
}



int main()
{
    
    return 0;
}