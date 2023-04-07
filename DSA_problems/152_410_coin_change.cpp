#include <bits/stdc++.h>
using namespace std;

// memoization
long long solve(int coins[], vector<vector<long long>> &dp, int i, int N, int target)
{
    if (i == 0)
    {
        if (target % coins[i] == 0)
            return 1;
        return 0;
    }

    if (dp[i][target] != -1)
        return dp[i][target];
    long long w1, w2;
    w1 = w2 = 0;
    if (target >= coins[i])
        w1 = solve(coins, dp, i, N, target - coins[i]);
    w2 = solve(coins, dp, i - 1, N, target);

    return dp[i][target] = w1 + w2;
}
long long int count(int coins[], int N, int sum)
{
    vector<vector<long long>> dp(N, vector<long long>(sum + 1, -1));
    return solve(coins, dp, N - 1, N, sum);
}

// tabulation
long long int count_tab(int coins[], int N, int sum)
{
    vector<vector<long long>> dp(N, vector<long long>(sum + 1, 0));

    for(int target = 0; target<=sum; target++)
    {
        if(target%coins[0] == 0) dp[0][target] =1;
    }
    for(int i =1; i<N; i++)
    {
        for(int target=0; target<=sum; target++)
        {
            long long w1, w2;
            w1 = w2 = 0;
            if (target >= coins[i]) w1 = dp[i][target - coins[i]];
            w2 = dp[i - 1][target];

            dp[i][target] = w1 + w2;
        }
    }
    return dp[N - 1][sum];
}

int main()
{

    return 0;
}