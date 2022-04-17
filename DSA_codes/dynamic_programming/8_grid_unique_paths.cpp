#include <bits/stdc++.h>
using namespace std;

//memoization
int solve(int m, int n, vector<vector<int>> &dp)
{
    if(m == 0 && n == 0) return 1;
    if(m < 0 || n < 0) return 0;

    if(dp[m][n] != -1) return dp[m][n];
    int up = solve(m, n-1, dp);
    int left = solve(m-1, n, dp);

    return dp[m][n] = up+left;
}

int uniquePaths(int m, int n) 
{
	vector<vector<int>> dp(m, vector<int>(n,-1));
    return solve(m-1, n-1, dp);
}


//tabulation
int uniquePaths_tab(int m, int n) 
{
	vector<vector<int>> dp(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i == 0 && j == 0) dp[i][j] = 1;
            else
            {
                int up =0, left=0;
        
                if(i>0)up = dp[i-1][j];
                if(j>0) left = dp[i][j-1];
                dp[i][j] = up+left;
            }
        }
        
    }
    return dp[m-1][n-1];
}

// tabulation with space optimization
int uniquePaths_tab1(int m, int n)
{
    vector<int> dp(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n, 0); // this is temp array which is created for every row to compute each cell in every row
        for (int j = 0; j < n; j++)
        {
            if(i == 0 && j == 0) temp[j] = 1; // exactly like the base in memoization
            else
            {
                temp[j] = dp[j] + temp[j-1]; //first parameter is for up and second is for left
            }
        }
        dp = temp; // after computation of every row the dp becomes the current computed row
        
    }
    return dp[n-1];
} 


int main()
{
    cout<<uniquePaths_tab(4,4);
    return 0;
}