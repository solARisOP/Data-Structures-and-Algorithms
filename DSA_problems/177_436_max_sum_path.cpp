#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

// memoization
int solve(int i, int j, vii &mat, vii &dp)
{
    if (j >= mat[0].size() || j < 0)
        return 0;
    if (i == mat.size() - 1)
        return mat[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int down = mat[i][j] + solve(i + 1, j, mat, dp);
    int left = mat[i][j] + solve(i + 1, j - 1, mat, dp);
    int right = mat[i][j] + solve(i + 1, j + 1, mat, dp);

    return dp[i][j] = max(down, max(left, right));
}
int maximumPath(int N, vii mat)
{
    // code here
    int maxi = 0;
    vii dp(N, vi(N, -1));
    for (int i = 0; i < N; i++)
    {
        maxi = max(maxi, solve(0, i, mat, dp));
    }
    return maxi;
}

// tabulation
int maximumPath_tab(int N, vii mat)
{
    // code here
    vii dp(N, vi(N, 0));
    for (int j = 0; j < N; j++)
    {
        dp[N - 1][j] = mat[N - 1][j];
    }
    for (int i = N - 2; i >= 0; i--)
    {
        for (int j = N - 1; j >= 0; j--)
        {
            int left = mat[i][j], right = mat[i][j];
            int down = mat[i][j] + dp[i + 1][j];
            if (j != 0)
                left = mat[i][j] + dp[i + 1][j - 1];
            if (j != N - 1)
                right = mat[i][j] + dp[i + 1][j + 1];

            dp[i][j] = max(down, max(left, right));
        }
    }

    int maxi = 0;
    for (int j = 0; j < N; j++)
    {
        maxi = max(maxi, dp[0][j]);
    }

    return maxi;
}

// space optimization
int maximumPath_SO(int N, vii mat)
{
    // code here
    vi curr(N, 0), after(N, 0);
    for (int j = 0; j < N; j++)
    {
        after[j] = mat[N - 1][j];
    }
    for (int i = N - 2; i >= 0; i--)
    {
        for (int j = N - 1; j >= 0; j--)
        {
            int left = mat[i][j], right = mat[i][j];
            int down = mat[i][j] + after[j];
            if (j != 0)
                left = mat[i][j] + after[j - 1];
            if (j != N - 1)
                right = mat[i][j] + after[j + 1];

            curr[j] = max(down, max(left, right));
        }
        after = curr;
    }

    int maxi = 0;
    for (int j = 0; j < N; j++)
    {
        maxi = max(maxi, after[j]);
    }

    return maxi;
}
int main()
{

    return 0;
}