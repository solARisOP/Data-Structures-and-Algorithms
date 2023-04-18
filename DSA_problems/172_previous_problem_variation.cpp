#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

// memoization
int solve(int i, int n, int a[], vi &dp)
{
    if (i >= n)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int take = a[i] + solve(i + 2, n, a, dp);
    int n_take = solve(i + 1, n, a, dp);

    return dp[i] = max(take, n_take);
}

int FindMaxSum(int arr[], int n)
{
    // Your code here
    vi dp(n, -1);
    return solve(0,n, arr, dp);
}

// tabulation
int FindMaxSum_tab(int a[], int n)
{
    // Your code here
    vi dp(n+2, 0);

    for(int i= n-1; i>=0; i--)
    {
        int take = a[i] + dp[i+2];
        int n_take = dp[i+1];

        dp[i] = max(take, n_take);
    }
    return dp[0];
}

// space optimization
int FindMaxSum_SO(int a[], int n)
{
    // Your code here
    vi dp(3, 0);

    for(int i= n-1; i>=0; i--)
    {
        int take = a[i] + dp[2];
        int n_take = dp[1];

        dp[0] = max(take, n_take);

        dp[2] = dp[1];
        dp[1] = dp[0];
    }
    return dp[0];
}

int main()
{

    return 0;
}