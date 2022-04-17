#include <bits/stdc++.h>
using namespace std;

// memoization
int solve(int m, int n, vector<vector<int>> &a, vector<vector<int>> &dp)
{
    if(m == 0 && n == 0 ) return a[m][n];
    if(m < 0 || n < 0) return 1e9;

    if(dp[m][n] != -1) return dp[m][n];
    int up = a[m][n] + solve(m-1, n, a, dp);
    int left = a[m][n] + solve(m, n-1, a, dp);

    return dp[m][n] = min(up, left);
}

int minSumPath(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(m-1, n-1, grid, dp);
}


// tabulation
int minSumPath_tab(vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i == 0 && j == 0 ) dp[i][j] = grid[i][j];
            else
            {
                int up = grid[i][j];
                if(i>0) up += dp[i-1][j];
                else up += 1e9; // by this it will be max and not considered

                int left = grid[i][j];
                if(j>0) left += dp[i][j-1];
                else left += 1e9;

                dp[i][j] = min(up, left);
            }
        }        
    }
    
    return dp[m-1][n-1];
}

//tabulation with space optimisation
int minSumPath_tab1(vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<int> dp(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n,0);
        for (int j = 0; j < n; j++)
        {
            if(i == 0 && j == 0 ) temp[j] = grid[i][j];
            else
            {
                int up = grid[i][j];
                if(i>0) up += dp[j];
                else up += 1e9; // by this it will be max and not considered

                int left = grid[i][j];
                if(j>0) left += temp[j-1];
                else left += 1e9;

                temp[j] = min(up, left);
            }
        }
        dp =temp;        
    }
    
    return dp[n-1];
}
int main()
{
    
    return 0;
}