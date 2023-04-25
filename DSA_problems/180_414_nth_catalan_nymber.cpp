#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

// memoization
int solve(int n, vi &dp)
{
    if (n == 0 || n == 1)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans+=(solve(n-i-1, dp)*solve(i, dp));
    }

    return dp[n] = ans;
}

int findCatalan(int n)
{
    // code here
    vi dp(n + 1, -1);
    return solve(n, dp);
}

// tabulation
int findCatalan(int n)
{
    // code here
    vi dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    for (int k = 2; k <= n; k++)
    {
        int ans = 0;
        for (int i = 0; i < k; i++)
        {
            ans += (dp[k - i - 1] * dp[i]);
        }

        dp[k] = ans;
    }
    return dp[n];
}

// optimaal
int solve_OP(int n)
{
    if (n <= 1)
        return 1;
    return n * solve_OP(n - 1);
}

int findCatalan_OP(int n)
{
    // code here
    int f = solve_OP(n);
    return solve_OP(2 * n) / (f * f * (n + 1));
}
int main()
{

    return 0;
}