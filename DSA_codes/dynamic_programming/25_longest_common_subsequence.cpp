#include <bits/stdc++.h>
using namespace std;

// memoization
int solve(int i1, int i2, string s, string t, vector<vector<int>> &dp)
{
    if(i1 < 0 || i2 < 0) return 0; //  if any one of them go negative

    if(dp[i1][i2] != -1) return dp[i1][i2];

    if(s[i1] == t[i2])
    {
        return dp[i1][i2] = 1 + solve(i1-1, i2-1, s, t, dp); // if it matches we go further with both
    }
    else
    {
        return dp[i1][i2] = 0 + max(solve(i1-1, i2, s, t, dp), solve(i1, i2-1, s, t, dp)); // if it does not matches we go with either of them and choose which one is max.        
    }
}

int lcs(string s, string t)
{
    int n1 = s.length();
    int n2 = t.length();

    vector<vector<int>> dp(n1, vector<int>(n2, -1));

	return solve(n1-1, n2-1, s, t, dp);
}

// memoization by right shifting the index
int solve(int i1, int i2, string s, string t, vector<vector<int>> &dp)
{
    if(i1 == 0 || i2 == 0) return 0; // // we have right shifted the index, thats why we check for 0 rather than -1;

    if(dp[i1][i2] != -1) return dp[i1][i2];

    if(s[i1-1] == t[i2-1]) // we have right shifted the index, thats why we are here checking for "index - 1"
    {
        return dp[i1][i2] = 1 + solve(i1-1, i2-1, s, t, dp); 
    }
    else
    {
        return dp[i1][i2] = 0 + max(solve(i1-1, i2, s, t, dp), solve(i1, i2-1, s, t, dp));         
    }
}

int lcs(string s, string t)
{
    int n1 = s.length();
    int n2 = t.length();

    vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));

	return solve(n1, n2, s, t, dp);
}

// tabulation with right shifted index 
int lcs(string s, string t)
{
    int n1 = s.length();
    int n2 = t.length();

    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
    for (int i = 0; i <= n1; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n2; j++)
    {
        dp[0][j] = 0;
    }
    
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if(s[i-1] == t[j-1]) 
            {
                dp[i][j] = 1 + dp[i-1][j-1]; 
            }
            else
            {
                dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);         
            }
        }
    }
    
	return dp[n1][n2];
}

// tabulation with space optimization
int lcs(string s, string t)
{
    int n1 = s.length();
    int n2 = t.length();

    vector<int> prev(n2+1, 0), curr(n2+1);

    for (int j = 0; j <= n2; j++)
    {
        prev[j] = 0;
    }
    
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if(s[i-1] == t[j-1]) 
            {
                curr[j] = 1 + prev[j-1]; 
            }
            else
            {
                curr[j] = 0 + max(prev[j], curr[j-1]);         
            }
        }
        prev = curr;
    }
    
	return prev[n2];
}

int main()
{
    
    return 0;
}