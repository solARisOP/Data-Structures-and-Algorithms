#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

int solve(int i, int j, int n, int a[], vii &dp)
{
    if (i == n)return 0;
    if (dp[i][j + 1] != -1)return dp[i][j + 1];

    int n_take = 0, take = 0;

    if (j == -1 || a[i] > a[j]) take = a[i] + solve(i + 1, i, n, a, dp);
    n_take = solve(i + 1, j, n, a, dp);

    return dp[i][j + 1] = max(take, n_take);
}
int maxSumIS(int n, int a[])
{
    // your code here
    vii dp(n, vi(n + 1, -1));
    return solve(0, -1, n, a, dp);
}

int main()
{

    return 0;
}