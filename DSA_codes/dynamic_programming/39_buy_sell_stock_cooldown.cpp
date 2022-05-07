#include <bits/stdc++.h>
using namespace std;

// memoization
int solve(int i, int buy, vector<int> &prices, int n, vector<vector<int>> &dp) // sol. taken from dp 35 with slight change
{
    if (i >= n)
        return 0;

    if (dp[i][buy] != -1)
        return dp[i][buy];

    if (buy == 1)
    {
        int take = -prices[i] + solve(i + 1, 0, prices, n, dp);
        int n_take = 0 + solve(i + 1, 1, prices, n, dp);
        return dp[i][buy] = max(take, n_take);
    }
    else
    {
        int take = prices[i] + solve(i + 2, 1, prices, n, dp); // i+2 because we cannot buy it the next day right after sell so that's why if we sell we go to the day after next
        int n_take = 0 + solve(i + 1, 0, prices, n, dp);
        return dp[i][buy] = max(take, n_take);
    }
}

int stockProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return solve(0, 1, prices, n, dp);
}

// tabulation
int stockProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0)); // becuase of an i+2 case we have to declare n+2 vector
    // no need to write the base case coz in base case all are 0 and we have initiaaly declared them 0
    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy == 1)
            {
                int take = -prices[i] + dp[i + 1][0];
                int n_take = 0 + dp[i + 1][1];
                dp[i][buy] = max(take, n_take);
            }
            else
            {
                int take = prices[i] + dp[i + 2][1];
                int n_take = 0 + dp[i + 1][0];
                dp[i][buy] = max(take, n_take);
            }
        }
    }
    return dp[0][1];
}

// tabulation with space optimization
int stockProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<int> front2(2, 0);
    vector<int> front1(2, 0);
    vector<int> curr(2, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        curr[1] = max(-prices[i] + front1[0], 0 + front1[1]);
        curr[0] = max(prices[i] + front2[1], 0 + front1[0]);

        front2 = front1;
        front1 = curr;
    }
    return curr[1];
}

int main()
{

    return 0;
}