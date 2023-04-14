#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

int solve(int n, int x, int y, int z, vi &dp)
{
    if (n == 0)return 0;
    if (dp[n] != -1) return dp[n];

    int sx, sy, sz, fl = 0;
    sx = sy = sz = INT_MIN;
    
    if (x <= n)
    {
        sx = 1 + solve(n - x, x, y, z, dp);
        fl = 1;
    }
    if (y <= n)
    {
        sy = 1 + solve(n - y, x, y, z, dp);
        fl = 1;
    }
    if (z <= n)
    {
        sz = 1 + solve(n - z, x, y, z, dp);
        fl = 1;
    }

    if (fl == 0) return dp[n] = INT_MIN;
    return dp[n] = max(sx, max(sy, sz));
}

int solve_new(int n, int x, int y, int z, vi & dp)
{
    if(n<0) return -1;
    if(n==0) return 0;

    if(dp[n] != INT_MIN) return dp[n];

    int sx= solve_new(n-x, x, y, z, dp);
    int sy= solve_new(n-y, x, y, z, dp);
    int sz= solve_new(n-z, x, y, z, dp);

    if(sx == -1 && sy == -1 && sz == -1) return dp[n] = -1;

    return dp[n] = 1 + max(sx, max(sy, sz));
}

int maximizeTheCuts(int n, int x, int y, int z)
{
    // Your code here
    if (x == 1 || y == 1 || z == 1)
        return n;
    vi dp(n + 1, -1);
    int ans = solve_new(n, x, y, z, dp);
    return (ans <= 0) ? 0 : ans;
}

int main()
{
    cout << maximizeTheCuts(100, 23, 15, 50);
    return 0;
}