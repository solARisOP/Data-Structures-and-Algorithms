#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

int solve(int i, int j, int n, int m, vector<vector<int>> &M, vector<vector<int>> &dp)
{
    if (i < 0 || i >= n || j >= m)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up, right, down;
    up = solve(i - 1, j + 1, n, m, M, dp);
    right = solve(i, j + 1, n, m, M, dp);
    down = solve(i + 1, j + 1, n, m, M, dp);

    return dp[i][j] = M[i][j] + max(up, max(right, down));
}
int maxGold(int n, int m, vector<vector<int>> M)
{
    int maxi = 0;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, solve(i, 0, n, m, M, dp));
    }

    return maxi;
}

int main()
{

    return 0;
}