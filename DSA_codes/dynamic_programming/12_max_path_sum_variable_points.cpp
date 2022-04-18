#include <bits/stdc++.h>
using namespace std;

//memoization
int solve(int i, int j, vector<vector<int>> &m, vector<vector<int>> &dp)
{
    if(j>=m[0].size() || j<0) return -1e9;
    if(i == 0) return m[0][j];
    if(dp[i][j] != -1) return dp[i][j];

    int up = m[i][j] + solve(i-1, j, m, dp);
    int ld = m[i][j] + solve(i-1, j-1, m, dp);
    int rd = m[i][j] + solve(i-1, j+1, m, dp);

    return dp[i][j] = max(up, max(ld,rd));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1));

    int maxi = -1e9;

    for (int j = 0; j < n; j++)
    {
        maxi = max(maxi,solve(m-1, j, matrix, dp));
    }

    return maxi;
}

// tabulation
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int j = 0; j < n; j++)
    {
        dp[0][j] = matrix[0][j];
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int up = matrix[i][j] + dp[i-1][j];

            int ld = matrix[i][j];
            if(j-1 >= 0)ld += dp[i-1][j-1];
            else ld += -1e9;

            int rd = matrix[i][j];
            if(j+1 < n)rd += dp[i-1][j+1];
            else rd += -1e9;

            dp[i][j] = max(up, max(ld, rd));
        }
        
    }

    int maxi = -1e9;

    for (int j = 0; j < n; j++)
    {
        maxi = max(maxi, dp[m-1][j]); // taking the maximum in the last row
    }

    return maxi;
}

//tabulation with space optimization
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

   vector<int> prev(n, 0);
   vector<int> curr(n, 0);

    for (int j = 0; j < n; j++)
    {
        prev[j] = matrix[0][j];
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int up = matrix[i][j] + prev[j];

            int ld = matrix[i][j];
            if(j-1 >= 0)ld +=prev[j-1];
            else ld += -1e9;

            int rd = matrix[i][j];
            if(j+1 < n)rd += prev[j+1];
            else rd += -1e9;

            curr[j] = max(up, max(ld, rd));
        }
        prev = curr;
    }

    int maxi = -1e9;

    for (int j = 0; j < n; j++)
    {
        maxi = max(maxi, prev[j]); 
    }

    return maxi;
}

int main()
{
    vector<vector<int>> m = {{1, 2, 10, 4},
                            {100, 3, 2, 1},
                            {1, 1, 20, 2},
                            {1, 2, 2, 1}};
                            cout<<getMaxPathSum(m);
    return 0;
}