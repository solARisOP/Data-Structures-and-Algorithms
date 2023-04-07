#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

// memoization
int solve(int i, int j, int arr[], vector<vector<int>> &dp)
{
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = 1e9;
    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + solve(i, k, arr, dp) + solve(k + 1, j, arr, dp);
        mini = min(steps, mini);
    }

    return dp[i][j] = mini;
}
int matrixMultiplication(int N, int arr[])
{
    // code here
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return solve(1, N - 1, arr, dp);
}

// tabulation
int matrixMultiplication(int N, int arr[])
{
    // code here
    vector<vector<int>> dp(N, vector<int>(N, 0));

    for (int i = N - 1; i > 0; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            int mini = 1e9;
            for (int k = i; k < j; k++)
            {
                int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                mini = min(steps, mini);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][N - 1];
}

int main()
{

    return 0;
}