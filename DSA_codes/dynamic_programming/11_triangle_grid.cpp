#include <bits/stdc++.h>
using namespace std;

//memoization
int solve(int i, int j, vector<vector<int>>& t, int n, vector<vector<int>> dp)
{
    if(i == n-1) return t[i][j];
    if(dp[i][j] != -1) return dp[i][j];

    int down = t[i][j] + solve(i+1, j, t, n, dp);
    int diag = t[i][j] + solve(i+1, j+1, t, n, dp);

    return dp[i][j] = min(down, diag);
}

int minimumPathSum(vector<vector<int>>& triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
	return solve(0,0,triangle, n, dp);
}

// tabulation
int minimumPathSum_tab(vector<vector<int>>& triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        dp[n-1][i] = triangle[n-1][i];
    }
    for (int i = n-2; i >= 0 ; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            //no base case here cause we have already computed it in the above for loop
            int down = triangle[i][j] + dp[i+1][j];
            int diag = triangle[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down, diag);
        }
        
    }
    return dp[0][0];
}

// tabulation with space optimisation
int minimumPathSum_tab1(vector<vector<int>>& triangle, int n)
{
    vector<int> dp (n);
    for (int i = 0; i < n; i++)
    {
        dp[i] = triangle[n-1][i];
    }
    for (int i = n-2; i >= 0 ; i--)
    {
        vector<int> temp(i+1);
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + dp[j];
            int diag = triangle[i][j] + dp[j+1];
            temp[j] = min(down, diag);
        }
        dp = temp;
    }
    return dp[0];
}

int main()
{
    
    return 0;
}