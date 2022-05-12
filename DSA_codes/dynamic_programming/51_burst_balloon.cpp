#include <bits/stdc++.h>
using namespace std;

// memoization
int solve(int i, int j, vector<int> &a, vector<vector<int>> &dp)
{
    if(i > j) return 0;

    if(dp[i][j] != -1) return dp[i][j];
 
    int maxi = -1e9;
    for (int k = i; k <= j; k++) // we are going reverse we are calculating from last remaining diamond to up, by this way the problems will not be dependent with each other but if we do vice-versa they will be dependent and as seen it will create a problem 
    {
        int cost = a[i-1] * a[k] * a[j+1] + solve(i, k-1, a, dp) + solve(k+1, j, a, dp);

        maxi = max(cost, maxi);
    }
    
    return dp[i][j] = maxi;
}

int maxCoins(vector<int>& a)
{
    int s = a.size();
	a.insert(a.begin(), 1);
    a.push_back(1);
    vector<vector<int>> dp(s+1, vector<int>(s+1, -1));
    return solve(1, s, a, dp);
}

// tabulation
int maxCoins(vector<int>& a)
{
    int s = a.size();
	a.insert(a.begin(), 1);
    a.push_back(1);
    vector<vector<int>> dp(s+2, vector<int>(s+2, 0));
    for (int i = s; i >= 1; i--)
    {
        for (int j = 1; j <= s; j++)
        {
            if(i>j) continue;
            int maxi = -1e9;
            for (int k = i; k <= j; k++)
            {
                int cost = a[i-1] * a[k] * a[j+1] + dp[i][k-1] + dp[k+1][j];

                maxi = max(cost, maxi);
            }

            dp[i][j] = maxi;
        }
    }
    
    return dp[1][s];
}

int main()
{
    
    return 0;
}