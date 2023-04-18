#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

// memoization
int solve(int n, int m, vii &mat, vii &dp, int &maxi)
{
    if (n == 0 || m == 0)
        return 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    int diagonal = solve(n - 1, m - 1, mat, dp, maxi);
    int up = solve(n - 1, m, mat, dp, maxi);
    int side = solve(n, m - 1, mat, dp, maxi);

    if (mat[n-1][m-1] == 1)
    {
        dp[n][m] = 1 + min(diagonal, min(up, side));
        maxi = max(maxi, dp[n][m]);
        return dp[n][m];
    }
    else
        return dp[n][m] = 0;
}

int maxSquare(int n, int m, vector<vector<int>> mat)
{
    // code here
    int maxi = 0;
    vii dp(n+1, vi(m+1, -1));
    solve(n, m, mat, dp, maxi);
    return maxi;
}

// tabulation
int maxSquare_tab(int n, int m, vector<vector<int>> mat)
{
    // code here
    int maxi = 0;
    vii dp(n+1, vi(m+1, 0));
    for(int i = 1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            int diagonal = dp[i - 1][j - 1];
            int up = dp[i - 1][j];
            int side = dp[i][j - 1];

            if (mat[i-1][j-1] == 1)
            {
                dp[i][j] = 1 + min(diagonal, min(up, side));
                maxi = max(maxi, dp[i][j]);
            }
            else dp[i][j] = 0;
        }
    }
    return maxi;
}

// space optimization
int maxSquare_SO(int n, int m, vector<vector<int>> mat)
{
    // code here
    int maxi = 0;
    vi prev(m+1, 0), curr(m+1, 0);
    for(int i = 1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            int diagonal = prev[j - 1];
            int up = prev[j];
            int side = curr[j - 1];

            if (mat[i-1][j-1] == 1)
            {
                curr[j] = 1 + min(diagonal, min(up, side));
                maxi = max(maxi, curr[j]);
            }
            else curr[j] = 0;
        }
        prev = curr;
    }

    return maxi;
}


int main()
{

    return 0;
}