#include <bits/stdc++.h>
using namespace std;

// memoization
bool solve(int i, int k, vector<int> &arr, vector<vector<int>> &dp)
{
    if (k == 0)
        return true;
    if (i == 0)
        return (arr[0] == k);

    if (dp[i][k] != -1)
        return dp[i][k];

    bool take = false;
    if (k >= arr[i])
        take = solve(i - 1, k - arr[i], arr, dp);
    bool n_take = solve(i - 1, k, arr, dp);

    return dp[i][k] = take | n_take; // if atleast any one of them is true then it will take true;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(n - 1, k, arr, dp);
}

// tabulation
bool subsetSumToK_tab(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true; // because if target is 0 then its true;
    }
    if(arr[0]<=k) dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int tar = 1; tar <= k; tar++)
        {
            bool n_take = dp[i - 1][tar];

            bool take = false;
            if (tar >= arr[i])
                take = dp[i - 1][tar - arr[i]];

            dp[i][tar] = take | n_take;
        }
    }

    return dp[n - 1][k];
}

// tabulation with space optimization
bool subsetSumToK_tab1(int n, int k, vector<int> &arr)
{
    vector<int> dp(k + 1), curr(k+1);

    dp[0] = curr[0] = true;
    if(arr[0]<=k) dp[arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int tar = 1; tar <= k; tar++)
        {
            bool n_take = dp[tar];

            bool take = false;
            if (tar >= arr[i])
                take = dp[tar - arr[i]];

            curr[tar] = take | n_take;
        }
        dp = curr;
    }

    return dp[k];
}

int main()
{

    return 0;
}