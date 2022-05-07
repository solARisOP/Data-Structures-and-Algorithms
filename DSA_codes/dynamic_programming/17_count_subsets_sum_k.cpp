#include <bits/stdc++.h>
using namespace std;

// memoization
int solve(int s, int i, vector<int> &num, vector<vector<int>> &dp)
{
    if(s == 0) return 1;
    if(i == 0) return (num[i] == s);

    if(dp[i][s] != -1) return dp[i][s];

    int pick = 0, n_pick = 0;
    if(num[i] <= s) pick += solve(s-num[i], i-1, num, dp);
    n_pick += solve(s, i-1, num, dp);

    return dp[i][s] = pick + n_pick; 
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int> (tar+1, -1));
    return solve(tar, n-1, num, dp);
}

// tabulation
int findWays_tab(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int> (tar+1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    if(num[0]<= tar) dp[0][num[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int s = 0; s <= tar; s++)
        {
            int pick = 0;
            if(num[i] <= s) pick = dp[i-1][s-num[i]];
            int n_pick = dp[i-1][s];
            dp[i][s] = pick + n_pick;
        }
    }

    return dp[n-1][tar];    
}

// tabulation with space optimization
int findWays_tab1(vector<int> &num, int tar)
{
    int n = num.size();
   vector<int> dp(tar+1, 0), curr(tar+1, 0);

    dp[0] = 1;
    if(num[0]<= tar) dp[num[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int s = 0; s <= tar; s++)
        {
            int pick = 0, n_pick = 0;
            if(num[i] <= s) pick += dp[s-num[i]];
            n_pick += dp[s];
            curr[s] = pick + n_pick;
        }
        dp =curr;
    }

    return dp[tar];    
}

int main()
{
    
    return 0;
}