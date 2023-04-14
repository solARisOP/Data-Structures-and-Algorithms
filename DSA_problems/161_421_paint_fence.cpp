#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

int mod = 1e9 + 7;

int add(int a, int b)
{
    return (a%mod + b%mod)%mod;
}

int solve(int n, int k, int prev, vii &dp)
{
    if (n == 0)
        return 1;

    if(dp[n][prev] != -1) return dp[n][prev];    
    
    int fl = 0;
    int ways = 0;
    
    if (prev == 2) k--;
    
    for (int i = 0; i < k; i++)
    {
        if (prev == 0) ways = add(ways, solve(n - 1, k, prev + 1, dp));
        else if (fl == 0 && prev == 1)
        {
            ways = add(ways, solve(n - 1, k, prev + 1, dp));
            fl++;
        }
        else if (fl == 1 && prev == 1) ways = add(ways, solve(n - 1, k, prev, dp));
        else ways = add(ways, solve(n - 1, k + 1, 1, dp));
    }
    
    return dp[n][prev] = ways;
}

long long countWays(int n, int k)
{
    // code here
    vii dp(n+1, vi(3, -1));
    return solve(n, k, 0, dp);
}

int main()
{

    return 0;
}