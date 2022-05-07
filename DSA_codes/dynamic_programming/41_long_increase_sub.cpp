#include <bits/stdc++.h>
using namespace std;

// memoization
int solve(int i, int j, int n, int arr[], vector<vector<int>> &dp)
{
    if(i == n) return 0;

    if(dp[i][j+1] != -1) return dp[i][j+1];

    int n_take = 0 + solve(i+1, j, n, arr, dp);
    int take = 0;
    if(j == -1 || arr[i]>arr[j]) take = 1 + solve(i+1, i, n, arr, dp);

    return dp[i][j+1] = max(n_take, take); 
}

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return solve(0, -1, n, arr, dp);
}


int main()
{
    
    return 0;
}