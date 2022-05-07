#include <bits/stdc++.h>
using namespace std;

// memoization
long solve(int i, int T, int* denominations, vector<vector<long>> &dp)
{
    if(i == 0) return (T % denominations[0] == 0); // because if it is divisible then it will return 1 as it was a way otherwise 0 because it was not the way

    if(dp[i][T] != -1) return dp[i][T];
    long pick =0;
    long n_pick = solve(i-1, T, denominations, dp);
    if(denominations[i]<= T)pick = solve(i, T-denominations[i], denominations, dp);

    return dp[i][T] = pick + n_pick;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value+1, -1));
    return solve(n-1, value, denominations, dp);
}

// tabulation	
long countWaysToMakeChange_tab(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value+1, 0));

    for (int T = 0; T <= value; T++)
    {
        dp[0][T] = (T % denominations[0] == 0);
    }

    for (int i = 1; i < n; i++)
    {
        for (int T = 0; T <= value; T++)
        {
            long pick =0;
            long n_pick = dp[i-1][T];
            if(denominations[i]<= T)pick = dp[i][T-denominations[i]];

            dp[i][T] = pick + n_pick;
        }
    }
    
    return dp[n-1][value];
}	

// tabulation with space optimization
long countWaysToMakeChange_tab(int *denominations, int n, int value)
{
    vector<long> prev(value+1, 0), curr(value+1, 0);

    for (int T = 0; T <= value; T++)
    {
        prev[T] = (T % denominations[0] == 0);
    }

    for (int i = 1; i < n; i++)
    {
        for (int T = 0; T <= value; T++)
        {
            long pick =0;
            long n_pick = prev[T];
            if(denominations[i]<= T)pick = curr[T-denominations[i]];

            curr[T] = pick + n_pick;
        }
        prev = curr;
    }
    
    return prev[value];
}		

int main()
{
    
    return 0;
}