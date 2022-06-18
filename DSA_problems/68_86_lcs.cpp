#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, int x, int y, string s1, string s2, vector<vector<int>> &dp)
{
    if(i == x || j == y) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j])
    {
        return dp[i][j] = 1 + solve(i+1, j+1, x, y, s1, s2, dp);
    }
    else
    {
        return dp[i][j] = max(solve(i+1, j, x, y, s1, s2, dp), solve(i, j+1, x, y, s1, s2, dp));
    }
}

int lcs(int x, int y, string s1, string s2)
{
    vector<vector<int>> dp(x, vector<int>(y, -1));
    return solve(0, 0, x, y, s1, s2, dp);
}    

int main()
{
    return 0;
}