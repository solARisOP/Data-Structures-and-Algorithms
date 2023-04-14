#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

// memoization
int solve(int i, int n, vi &a, vi &dp)
{
    if (i >= n)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int take = 0;
    if(i!= n-1)take = a[i] + a[i + 1] + solve(i + 3, n, a, dp);
    int take_1 = a[i] + solve(i + 2, n, a, dp);
    int n_take = solve(i + 1, n, a, dp);

    return dp[i] = max({take, take_1, n_take});
}
int findMaxSum(vector<int> &a)
{
    // Code Here
    int n = a.size();
    vi dp(n, -1);
    return solve(0, n, a, dp);
}

// tabulation
int findMaxSum(vector<int> &a)
{
    // Code Here
    int n = a.size();
    vi dp(n+3, 0);
    for(int i = n-1; i>=0; i--)
    {
        int take = 0;
        if(i!= n-1)take = a[i] + a[i + 1] + dp[i + 3];
        int take_1 = a[i] + dp[i + 2];
        int n_take = dp[i + 1];

        dp[i] = max({take, take_1, n_take});
    }
    return solve(0, n, a, dp);
}
int main()
{

    return 0;
}