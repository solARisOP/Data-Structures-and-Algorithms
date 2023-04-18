#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

int solve(int n, int m, vii &mat, vii &dp, int &maxi)
{
    if (n < 0 || m < 0)
        return 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    int diagonal = solve(n - 1, m - 1, mat, dp, maxi);
    int up = solve(n - 1, m, mat, dp, maxi);
    int side = solve(n, m - 1, mat, dp, maxi);

    if (mat[n][m] == 1)
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
    vii dp(n, vi(m, -1));
    solve(n - 1, m - 1, mat, dp, maxi);
    return maxi;
}

int main()
{

    return 0;
}