#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

// memoization
int fact(int n, int r, vector<vector<int>> &dp)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    if (r == n)
        return 1;
    if (r == 1)
        return n;

    if (dp[n][r] != -1)
        return dp[n][r];
    return dp[n][r] = (fact(n - 1, r - 1, dp) % mod + fact(n - 1, r, dp) % mod) % mod;
}
int nCr(int n, int r)
{
    // code here
    vector<vector<int>> dp(n + 1, vector<int>(r + 1, -1));
    return fact(n, r, dp);
}

// tabulation
int nCr_tab(int n, int r)
{
    vector<vector<int>> dp(n + 1, vector<int>(r + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= r; j++)
        {
            if (i == j || j == 0)
                dp[i][j] = 1;
            if (j == 1)
                dp[i][j] = i;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= r; j++)
        {
            dp[i][j] = (dp[i - 1][j - 1] % mod + dp[i - 1][j] % mod) % mod;
        }
    }

    return dp[n][r];
}

int main()
{

    return 0;
}