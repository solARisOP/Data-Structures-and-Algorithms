#include <bits/stdc++.h>
using namespace std;

// memoization
int solve(int i, int buy, int cap, int n, vector<int>& prices, vector<vector<vector<int>>> &dp)
{
    if(cap == 0) return 0; // if the transaction limit is exhausted then no further proceding
    if(i == n) return 0;

    if(dp[i][buy][cap] != -1) return dp[i][buy][cap];

    if(buy)
    {
        int b = -prices[i] + solve(i+1, 0, cap, n, prices, dp); // bought doesnot mean that the transaction is complete, we have to sell for that thats why cap[ is same]
        int nb = 0 + solve(i+1, 1, cap, n, prices, dp); //didn't bought nothing happened
        return dp[i][buy][cap] = max(b, nb);
    }
    else
    {
        int s = prices[i] + solve(i+1, 1, cap-1, n, prices, dp); // sold thats why transaction is completed and cap is reduced by 1
        int ns = 0 + solve(i+1, 0, cap, n, prices, dp); // didn't sold transaction not completed cap doesnot reduced
        return dp[i][buy][cap] = max(s, ns);
    }
}

int maxProfit(vector<int>& prices, int n)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1))); // the extra variable is for the atmost 2 limit
    return solve(0, 1, 2, n, prices, dp);
}

// tabulation
int maxProfit(vector<int>& prices, int n)
{
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0))); 
    // no base casses needed coz all the base cases are initialized to 0 and initially the dp array is 0
    for (int i = n-1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                if(buy)
                {
                    int b = -prices[i] + dp[i+1][0][cap]; 
                    int nb = 0 + dp[i+1][1][cap];
                    dp[i][buy][cap] = max(b, nb);
                }
                else
                {
                    int s = prices[i] + dp[i+1][1][cap-1]; 
                    int ns = 0 + dp[i+1][0][cap]; 
                    dp[i][buy][cap] = max(s, ns);
                }
            }   
        }
    }
    
    return dp[0][1][2];
}

// tabulation with space optimizaton
int maxProfit(vector<int>& prices, int n)
{
    vector<vector<int>> after(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0)); 
    // no base casses needed coz all the base cases are initialized to 0 and initially the dp array is 0
    for (int i = n-1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                if(buy)
                {
                    int b = -prices[i] + after[0][cap]; 
                    int nb = 0 + after[1][cap];
                    curr[buy][cap] = max(b, nb);
                }
                else
                {
                    int s = prices[i] + after[1][cap-1]; 
                    int ns = 0 + after[0][cap]; 
                    curr[buy][cap] = max(s, ns);
                }
            }   
        }
        after = curr;
    }
    
    return after[1][2];
}

int main()
{
    
    return 0;
}