#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int solve(int i, int j, vector<vector<int>> &dp)
{
    if (!i && !j)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    int a = 0, b = 0;
    if (i - 1 >= 0)
        a = solve(i - 1, j, dp);
    if (j - 1 >= 0)
        b = solve(i, j - 1, dp);

    return dp[i][j] = a + b;
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(m - 1, n - 1, dp);
}

int main()
{

    return 0;
}