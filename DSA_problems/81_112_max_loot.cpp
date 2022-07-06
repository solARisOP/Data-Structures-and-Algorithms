#include <bits/stdc++.h>
using namespace std;

int solve(int i, int arr[], int n, vector<int> &dp)
{
    if (i >= n)
        return 0;
    if (i == n - 1)
    {
        return arr[i];
    }

    if (dp[i] != -1)
        return dp[i];

    int loot = arr[i] + solve(i + 2, arr, n, dp);
    int go = solve(i + 1, arr, n, dp);

    return dp[i] = max(go, loot);
}

int FindMaxSum(int arr[], int n)
{
    vector<int> dp(n, -1);
    return solve(0, arr, n, dp);
}

int main()
{

    return 0;
}