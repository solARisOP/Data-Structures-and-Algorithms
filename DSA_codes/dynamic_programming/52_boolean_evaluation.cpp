#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int mod = 1000000007;

// memoization
ll solve(int i, int j, int istrue, string &exp, vector<vector<vector<int>>> &dp)
{
    if(i>j) return 0;
    if(i == j)
    {
        if(istrue == 1) return exp[i] == 'T';
        else return exp[i] == 'F';
    }

    if(dp[i][j][istrue] != -1) return dp[i][j][istrue];

    int ways = 0;
    for (int k = i+1; k < j; k+=2)
    {
        ll rt = solve(k+1, j, 1, exp, dp);
        ll rf = solve(k+1, j, 0, exp, dp);
        ll lt = solve(i, k-1, 1, exp, dp);
        ll lf = solve(i, k-1, 0, exp, dp);

        if(exp[k] == '&')
        {
            if(istrue == 1) ways = (ways + (rt*lt)%mod)%mod; // we are finding number of ways of true if it is '&' and both left and right gave us true
            else ways = (ways +(lf*rt)%mod + (lt*rf)%mod + (lf*rf)%mod)%mod;
        }

        else if(exp[k] == '|')
        {
            if(istrue == 1) ways = (ways +(rt*lt)%mod + (lf*rt)%mod + (lt*rf)%mod)%mod;
            else ways = (ways +(lf*rf)%mod)%mod;
        }

        else if(exp[k] == '^')
        {
            if(istrue == 1) ways = (ways +(lf*rt)%mod + (lt*rf)%mod)%mod;
            else ways = (ways +(rt*lt)%mod + (lf*rf)%mod)%mod;
        }
    }

    return dp[i][j][istrue] = ways;    
}

int evaluateExp(string & exp) 
{
    int n = exp.length();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
    return solve(0, n-1, 1, exp, dp);
}

// tabulation
int evaluateExp(string & exp) 
{
    int n = exp.length();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));
    
    for (int i = n-1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            // base cases
            if(i>j) continue;
            if(i == j)
            {
            dp[i][i][1] = (exp[i] == 'T');
            dp[i][i][0] = (exp[i] == 'F');
            }

            for (int k = i+1; k < j; k+=2)
            {
                ll rt = dp[k+1][j][1];
                ll rf = dp[k+1][j][0];
                ll lt = dp[i][k-1][1];
                ll lf = dp[i][k-1][0];

                if(exp[k] == '&')
                {
                    dp[i][j][1] = (dp[i][j][1] + (rt*lt)%mod)%mod;
                    dp[i][j][0] = (dp[i][j][0] +(lf*rt)%mod + (lt*rf)%mod + (lf*rf)%mod)%mod;
                }

                else if(exp[k] == '|')
                {
                    dp[i][j][1] = (dp[i][j][1] +(rt*lt)%mod + (lf*rt)%mod + (lt*rf)%mod)%mod;
                    dp[i][j][0] = (dp[i][j][0] +(lf*rf)%mod)%mod;
                }

                else if(exp[k] == '^')
                {
                    dp[i][j][1] = (dp[i][j][1] +(lf*rt)%mod + (lt*rf)%mod)%mod;
                    dp[i][j][0] = (dp[i][j][0] +(rt*lt)%mod + (lf*rf)%mod)%mod;
                }
            }
        }    
    }
    
    return dp[0][n-1][1];
}

int main()
{
    
    return 0;
}