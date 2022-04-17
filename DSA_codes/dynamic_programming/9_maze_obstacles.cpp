#include <bits/stdc++.h>
using namespace std;

int mod = (1e9 +7);

//memoization
int solve(int n, int m, vector<vector<int>> &dp, vector< vector< int> > &mat)
{
    if(n == 0 && m == 0) return 1;
    if(n < 0 || m < 0) return 0;
    if((n>=0 && m>=0) && mat[n][m] == -1) return 0;


    if(dp[n][m] != -1) return dp[n][m];
    int up = solve(n, m-1, dp, mat);
    int left = solve(n-1, m, dp, mat);

    return dp[n][m] = up+left;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat)
{
	vector<vector<int>> dp(m, vector<int>(n,-1));
    return solve(n-1, m-1, dp, mat);
}

//tabulation
int mazeObstacles_tab(int n, int m, vector< vector< int> > &mat) 
{
	vector<vector<int>> dp(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(i == 0 && j == 0) dp[i][j] = 1;
            else if((i>=0 && j>=0) && mat[i][j] == -1) dp[i][j] = 0;
            else
            {
                int up =0, left=0;
                if(i>0) up = dp[i-1][j];
                if(j>0) left = dp[i][j-1];
                dp[i][j] = (up+left) % mod;
            }
        }
        
    }
    return dp[n-1][m-1];
}

// tabulation with space optimisation
int mazeObstacles_tab1(int n, int m, vector< vector< int> > &mat) 
{
	vector<int> dp (m,0);

    for (int i = 0; i < n; i++)
    {
        vector<int>temp (m,0);
        for (int j = 0; j < m; j++)
        {
            if(i == 0 && j == 0) temp[j] = 1;
            else if((i>=0 && j>=0) && mat[i][j] == -1) temp[j] = 0;
            else
            {
                temp[j] = (dp[j]+temp[j-1]) % mod; // because the answer was asked in modulo form
            }
        }
        dp = temp;
    }
    return dp[m-1];
}

int main()
{
    
    return 0;
}