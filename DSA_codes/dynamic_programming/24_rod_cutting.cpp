#include <bits/stdc++.h>
using namespace std;


// memoization
int solve(int i, int n, vector<int> &price, vector<vector<int>> &dp)
{
    if(n == 0) return 0;
    if(i == 0) return n * price[0]; // because at i = 0, the r_len will be 1 and we can cut the rods n no. of times so we return the following

    if(dp[i][n] != -1) return dp[i][n];

    int pick = -1e9;
    int n_pick = 0 + solve(i-1, n, price, dp);
    int r_len = i+1;
    if(r_len <= n) pick = price[i] + solve(i, n-r_len, price, dp); // because we can cut the rof at the same length any number of times that's why its a type of infinite supply

    return dp[i][n] = max(pick, n_pick);
}

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
	return solve(n-1, n, price, dp);
}

//tabulation
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n+1, 0));

    for (int N = 0; N <= n; N++)
    {
        dp[0][N] = N*price[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int N = 0; N <= n; N++)
        {
            int pick = -1e9;
            int n_pick = 0 + dp[i-1][N];
            int r_len = i+1;
            if(r_len <= N) pick = price[i] + dp[i][N-r_len]; 

            dp[i][N] = max(pick, n_pick);
        }
    }
    
	return dp[n-1][n];
}

// tabulation with space optimization
int cutRod(vector<int> &price, int n)
{
    vector<int> prev(n+1, 0), curr(n+1, 0);

    for (int N = 0; N <= n; N++)
    {
        prev[N] = N*price[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int N = 0; N <= n; N++)
        {
            int pick = -1e9;
            int n_pick = 0 + prev[N];
            int r_len = i+1;
            if(r_len <= N) pick = price[i] + curr[N-r_len]; 

            curr[N] = max(pick, n_pick);
        }
        prev = curr;
    }
    
	return prev[n];
}

// tabulation with 1-d array space optimization
int cutRod(vector<int> &price, int n)
{
    vector<int> prev(n+1, 0);

    for (int N = 0; N <= n; N++)
    {
        prev[N] = N*price[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int N = 0; N <= n; N++)
        {
            int pick = -1e9;
            int n_pick = 0 + prev[N];
            int r_len = i+1;
            if(r_len <= N) pick = price[i] + prev[N-r_len]; 

            prev[N] = max(pick, n_pick);
        }
    }
    
	return prev[n];
}

int main()
{
    
    return 0;
}